class Solution(object):
    def countInterestingSubarrays(self, p, q, r):
        x = {0: 1}
        u, v = 0, 0
        for w in p:
            v += (w % q == r)
            u += x.get((v - r + q) % q, 0)
            x[(v % q)] = x.get((v % q), 0) + 1
        return u
