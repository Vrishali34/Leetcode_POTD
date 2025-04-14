class Solution(object):
    def countGoodTriplets(self, z, x, y, w):
        r, n = 0, len(z)
        for i in range(n):
            for j in range(i + 1, n):
                if abs(z[i] - z[j]) <= x:
                    for k in range(j + 1, n):
                        if abs(z[j] - z[k]) <= y and abs(z[i] - z[k]) <= w:
                            r += 1
        return r
