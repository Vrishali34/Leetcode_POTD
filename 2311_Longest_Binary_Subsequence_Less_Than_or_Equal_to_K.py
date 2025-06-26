class Solution(object):
    def longestSubsequence(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        sub_val = 0
        sub_len = 0
        str_len = len(s)

        for i in range(str_len - 1, -1, -1):
            if s[i] == '0':
                sub_len += 1
            elif sub_val + (1 << (str_len - 1 - i)) <= k:
                sub_val += (1 << (str_len - 1 - i))
                sub_len += 1
        return sub_len
