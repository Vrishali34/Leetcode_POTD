class Solution(object):
    def mincostTickets(self, t, f):
        l = len(t)
        p = q = 0
        r = [0] * l
        for i in range(l):
            while t[i] - t[p] >= 7: p += 1
            while t[i] - t[q] >= 30: q += 1
            r[i] = min((r[i - 1] if i > 0 else 0) + f[0], 
                       (r[p - 1] if p > 0 else 0) + f[1], 
                       (r[q - 1] if q > 0 else 0) + f[2])
        return r[-1]
