from collections import Counter

class Solution(object):
    def countBalancedPermutations(self, num):
        """
        :type num: str
        :rtype: int
        """
        
       
        def comb(n, k):
            if k > n:
                return 0
            if k == 0 or k == n:
                return 1
            num = 1
            denom = 1
            for i in range(k):
                num *= n - i
                denom *= i + 1
            return num // denom
        
        def dfs(i, j, a, b, memo):
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
                    t = comb(a, l) * comb(b, r) * dfs(i + 1, j - l * i, a - l, b - r, memo)
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
        return dfs(0, s // 2, n // 2, (n + 1) // 2, {})
