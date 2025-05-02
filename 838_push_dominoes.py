class Solution(object):
    def pushDominoes(self, d):
        n = len(d)
        L = [0] * n
        R = [0] * n
        f = 0
        for i in range(n):
            if d[i] == 'R':
                f = n
            elif d[i] == 'L':
                f = 0
            else:
                f = max(f - 1, 0)
            R[i] = f
        f = 0
        for i in range(n - 1, -1, -1):
            if d[i] == 'L':
                f = n
            elif d[i] == 'R':
                f = 0
            else:
                f = max(f - 1, 0)
            L[i] = f
        res = []
        for l, r in zip(L, R):
            if l == r:
                res.append('.')
            elif l > r:
                res.append('L')
            else:
                res.append('R')
        return ''.join(res)
