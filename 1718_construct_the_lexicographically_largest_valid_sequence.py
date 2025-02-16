class Solution(object):
    def constructDistancedSequence(self, n):
        z = [0] * (2 * n - 1)
        y = [False] * (n + 1)

        def f(x):
            if x == len(z): return True
            if z[x]: return f(x + 1)
            for v in range(n, 0, -1):
                if y[v]: continue
                j = x if v == 1 else x + v
                if j >= len(z) or z[j]: continue
                z[x], z[j] = v, v
                y[v] = True
                if f(x + 1): return True
                z[x], z[j] = 0, 0
                y[v] = False
            return False

        f(0)
        return z
