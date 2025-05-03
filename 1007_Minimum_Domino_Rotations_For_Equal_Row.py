class Solution(object):
    def minDominoRotations(self, p, q):
        for d in (p[0], q[0]):
            a = b = 0
            for i in range(len(p)):
                if p[i] != d and q[i] != d: break
                if p[i] != d: a += 1
                if q[i] != d: b += 1
            else:
                return min(a, b)
        return -1
