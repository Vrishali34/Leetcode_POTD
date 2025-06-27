class Solution(object):
    def longestSubsequenceRepeatedK(self, s, k):
        from collections import Counter
        f = Counter(s)
        chars = [chr(i) for i in range(122, 96, -1) if f[chr(i)] >= k]
        ans = ''

        def valid(p):
            i = j = cnt = 0
            while i < len(s) and cnt < k:
                if s[i] == p[j]: j += 1
                if j == len(p): cnt += 1; j = 0
                i += 1
            return cnt == k

        def dfs(path):
            nonlocal ans
            if len(path) > 7: return
            if valid(path):
                if len(path) > len(ans) or (len(path) == len(ans) and path > ans):
                    ans = path
                for c in chars: dfs(path + c)

        dfs('')
        return ans
