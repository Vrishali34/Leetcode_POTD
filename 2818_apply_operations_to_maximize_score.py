class Solution(object):
    def maximumScore(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        import sys
        sys.setrecursionlimit(10**7)
        from collections import defaultdict
        from functools import cmp_to_key

        MOD = 10**9 + 7
        n = len(nums)
        MAX = 100002

        # Step 1: Smallest Prime Factor (SPF) Sieve
        f = list(range(MAX))
        for i in range(2, int(MAX**0.5) + 1):
            for j in range(i*i, MAX, i):
                f[j] = min(f[j], i)

        # Step 2: Count distinct prime factors for each nums[i]
        g = [0] * n
        for i in range(n):
            s = set()
            x = nums[i]
            while x > 1:
                s.add(f[x])
                x //= f[x]
            g[i] = len(s)

        # Step 3: Left and Right bounds (monotonic stack)
        l, r = [-1] * n, [n] * n
        stack = []
        for i in range(n - 1, -1, -1):
            while stack and g[stack[-1]] <= g[i]:
                l[stack.pop()] = i
            stack.append(i)

        stack = []
        for i in range(n):
            while stack and g[stack[-1]] < g[i]:
                r[stack.pop()] = i
            stack.append(i)

        # Step 4: Sort indices by nums[i] descending, then i ascending
        idx = list(range(n))
        idx.sort(key=lambda i: (-nums[i], i))

        # Step 5: Compute result using modular exponentiation
        def mod_pow(base, exp, mod):
            res = 1
            while exp:
                if exp % 2:
                    res = res * base % mod
                base = base * base % mod
                exp //= 2
            return res

        res = 1
        for i in idx:
            cnt = (i - l[i]) * (r[i] - i)
            cnt = min(k, cnt)
            k -= cnt
            res = res * mod_pow(nums[i], cnt, MOD) % MOD
            if k == 0:
                break

        return res
