class Solution(object):
    def divideArray(self, u):
        v = [0] * 501
        for w in u: v[w] ^= 1
        return sum(v) == 0
