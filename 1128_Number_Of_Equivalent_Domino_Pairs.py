class Solution(object):
    def numEquivDominoPairs(self, q):
        b, z = [0]*100, 0
        for u in q:
            v = min(u)*10 + max(u)
            z += b[v]
            b[v] += 1
        return z
