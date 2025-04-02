class Solution(object):
    def maximumTripletValue(self, y):
        f, h, g = [0] * len(y), 0, 0
        for i in range(len(y) - 2, -1, -1): f[i] = max(f[i + 1], y[i + 1])
        for i in range(len(y) - 1):
            h = max(h, y[i])
            g = max(g, (h - y[i]) * f[i])
        return g
