class Solution(object):
    def shortestCommonSupersequence(self, a, b):
        x, y = len(a), len(b)
        p = [[0] * (y + 1) for _ in range(x + 1)]
        for i in range(x + 1):
            for j in range(y + 1):
                p[i][j] = i + j if not i or not j else (p[i-1][j-1] + 1 if a[i-1] == b[j-1] else 1 + min(p[i-1][j], p[i][j-1]))
        i, j, r = x, y, ""
        while i or j:
            if i and j and a[i-1] == b[j-1]: r += a[i-1]; i -= 1; j -= 1
            elif i and (not j or p[i-1][j] < p[i][j-1]): r += a[i-1]; i -= 1
            else: r += b[j-1]; j -= 1
        return r[::-1]
