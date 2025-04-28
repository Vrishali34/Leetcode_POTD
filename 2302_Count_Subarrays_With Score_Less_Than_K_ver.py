class Solution(object):
    def countSubarrays(self, p, q):
        r = s = t = 0
        for u in range(len(p)):
            s += p[u]
            while s * (u - t + 1) >= q:
                s -= p[t]
                t += 1
            r += u - t + 1
        return r
