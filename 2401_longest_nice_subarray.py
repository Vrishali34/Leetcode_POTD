class Solution(object):
    def longestNiceSubarray(self, z):
        a = b = c = 0
        for i in range(len(z)):
            while a & z[i]: a ^= z[b]; b += 1
            a |= z[i]
            c = max(c, i - b + 1)
        return c
