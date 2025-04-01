class Solution(object):
    def mostPoints(self, q):
        n = len(q)
        x = [0] * (n + 1)
        for y in range(n - 1, -1, -1):
            x[y] = max(q[y][0] + (x[y + q[y][1] + 1] if y + q[y][1] + 1 < n else 0), x[y + 1])
        return x[0]
