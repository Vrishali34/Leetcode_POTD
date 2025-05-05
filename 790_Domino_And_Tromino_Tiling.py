class Solution(object):
    def numTilings(self, n):
        if n < 4: return [0,1,2,5][n]
        a, b, c, m = 1, 2, 5, 10**9 + 7
        for _ in range(4, n + 1): a, b, c = b, c, (2 * c + a) % m
        return c
