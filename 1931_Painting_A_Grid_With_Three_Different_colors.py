class Solution(object):
    def colorTheGrid(self, m, n):
        MOD = 10**9 + 7
        patterns = []

        def gen(row, curr):
            if row == m:
                patterns.append(tuple(curr))
                return
            for c in range(3):
                if row == 0 or curr[-1] != c:
                    gen(row + 1, curr + [c])

        gen(0, [])
        idx_map = {p: i for i, p in enumerate(patterns)}
        size = len(patterns)

        trans = [[] for _ in range(size)]
        for i in range(size):
            for j in range(size):
                if all(x != y for x, y in zip(patterns[i], patterns[j])):
                    trans[i].append(j)

        dp = [1] * size
        for _ in range(n - 1):
            nxt = [0] * size
            for i in range(size):
                for j in trans[i]:
                    nxt[j] = (nxt[j] + dp[i]) % MOD
            dp = nxt

        return sum(dp) % MOD
