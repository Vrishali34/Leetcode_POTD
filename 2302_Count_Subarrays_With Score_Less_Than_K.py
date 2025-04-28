class Solution(object):
    def countSubarrays(self, a, b):
        c = d = e = 0
        for f in range(len(a)):
            d += a[f]
            while d * (f - e + 1) >= b:
                d -= a[e]
                e += 1
            c += f - e + 1
        return c
