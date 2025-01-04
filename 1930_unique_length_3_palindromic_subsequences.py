class Solution(object):
    def countPalindromicSubsequence(self, d):
        sz, ans = len(d), 0
        left, right = [-1] * 26, [sz] * 26
        for i, ch in enumerate(d):
            idx = ord(ch) - ord('a')
            if left[idx] == -1: left[idx] = i
            right[idx] = i
        for i in range(26):
            if left[i] != -1 and right[i] != sz:
                chars = set(d[left[i] + 1:right[i]])
                ans += len(chars)
        return ans
