###inline sum tracking
class Solution(object):
    def isZeroArray(self, p, q):
        z = [0]*(len(p)+1)
        for u in q:
            z[u[0]] += 1
            z[u[1]+1] -= 1
        for i in range(1, len(p)): z[i] += z[i-1]
        return all(z[i] >= p[i] for i in range(len(p)))
