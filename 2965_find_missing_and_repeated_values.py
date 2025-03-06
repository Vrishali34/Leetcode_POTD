class Solution(object):
    def findMissingAndRepeatedValues(self, grid):
        n, N = len(grid), len(grid) * len(grid)
        S, S2 = N * (N + 1) // 2, N * (N + 1) * (2 * N + 1) // 6
        A = B = 0
        for r in grid:
            for v in r:
                A += v
                B += v * v
        d1, d2 = A - S, B - S2
        rep = (d1 + d2 // d1) // 2
        return [rep, rep - d1]
