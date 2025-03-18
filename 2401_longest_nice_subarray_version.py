class Solution(object):
    def longestNiceSubarray(self, w):
        a = b = c = 0
        for i in range(len(w)):
            while a & w[i]: a ^= w[b]; b += 1
            a |= w[i]
            c = max(c, i - b + 1)
        return c
