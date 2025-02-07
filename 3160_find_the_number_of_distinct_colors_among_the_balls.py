class Solution(object):
    def queryResults(self, x, y):
        z, a, b = len(y), {}, {}
        w = [0] * z
        for i in range(z):
            c, d = y[i]
            if c in a:
                e = a[c]
                b[e] -= 1
                if b[e] == 0: del b[e]
            a[c] = d
            b[d] = b.get(d, 0) + 1
            w[i] = len(b)
        return w
