class Solution(object):
    def idealArrays(self, n, maxValue):
        """
        :type n: int
        :type maxValue: int
        :rtype: int
        """
        MOD = 10**9 + 7
        MAXLEN = 14  # log2(10^4)

        # Precompute all divisors
        divisors = [[] for _ in range(maxValue + 1)]
        for i in range(1, maxValue + 1):
            for j in range(i * 2, maxValue + 1, i):
                divisors[j].append(i)

        # dp[length][value]: number of sequences of length 'length' ending in 'value'
        dp = [[0] * (maxValue + 1) for _ in range(MAXLEN + 1)]
        for i in range(1, maxValue + 1):
            dp[1][i] = 1

        for length in range(2, MAXLEN + 1):
            for val in range(1, maxValue + 1):
                for d in divisors[val]:
                    dp[length][val] = (dp[length][val] + dp[length - 1][d]) % MOD

        # Total ideal arrays of each length
        total = [0] * (MAXLEN + 1)
        for length in range(1, MAXLEN + 1):
            total[length] = sum(dp[length]) % MOD

        # Precompute factorials and modular inverses
        fact = [1] * (n + 1)
        invfact = [1] * (n + 1)
        for i in range(1, n + 1):
            fact[i] = fact[i - 1] * i % MOD
        invfact[n] = pow(fact[n], MOD - 2, MOD)
        for i in range(n - 1, -1, -1):
            invfact[i] = invfact[i + 1] * (i + 1) % MOD

        # Combine counts with combinatorics: C(n-1, length-1)
        result = 0
        for length in range(1, min(MAXLEN, n) + 1):
            comb = fact[n - 1] * invfact[length - 1] % MOD * invfact[n - length] % MOD
            result = (result + total[length] * comb) % MOD

        return result
