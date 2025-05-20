class Solution(object):
    def isZeroArray(self, a, b):
        d = [0]*(len(a)+2)
        for l, r in b:
            d[l] += 1
            d[r+1] -= 1
        for i in range(1, len(a)): d[i] += d[i-1]
        return all(d[i] >= a[i] for i in range(len(a)))
