from collections import Counter

class Solution(object):
    def countBalancedPermutations(self, num):
        def compute_combinations(n, mod):
            comb = [[0] * (n + 1) for _ in range(n + 1)]
            for i in range(n + 1):
                comb[i][0] = comb[i][i] = 1
            for i in range(1, n + 1):
                for j in range(1, i):
                    comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod
            return comb
        
        def dfs(i, j, a, b, memo, mod, comb):
            if i > 9:
                return (j | a | b) == 0
            if a == 0 and j:
                return 0
            if (i, j, a, b) in memo:
                return memo[(i, j, a, b)]
            ans = 0
            for l in range(min(cnt[i], a) + 1):
                r = cnt[i] - l
                if 0 <= r <= b and l * i <= j:
                    t = comb[a][l] * comb[b][r] * dfs(i + 1, j - l * i, a - l, b - r, memo, mod, comb)
                    ans = (ans + t) % mod
            memo[(i, j, a, b)] = ans
            return ans

        nums = list(map(int, num))
        s = sum(nums)
        if s % 2:
            return 0
        n = len(nums)
        mod = 10**9 + 7
        cnt = Counter(nums)
        comb = compute_combinations(n, mod)
        return dfs(0, s // 2, n // 2, (n + 1) // 2, {}, mod, comb)
