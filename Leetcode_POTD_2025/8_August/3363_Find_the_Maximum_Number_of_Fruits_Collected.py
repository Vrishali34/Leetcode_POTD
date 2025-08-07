class Solution(object):
    def maxCollectedFruits(self, z):
        """
        :type z: List[List[int]]
        :rtype: int
        """
        n = len(z)
        r = sum(z[i][i] for i in range(n))

        for i in range(n - 2):
            z[i][n - 2 - i] = 0
            z[i][n - 3 - i] = 0

        z[n - 2][0] = 0

        for i in range(1, n - 1):
            for j in range(max(i + 1, n - i - 1), n):
                max_val = z[i - 1][j]
                max_val = max(max_val, z[i - 1][j - 1])
                if j + 1 < n:
                    max_val = max(max_val, z[i - 1][j + 1])
                z[i][j] += max_val

        for j in range(1, n - 1):
            for i in range(max(j + 1, n - j - 1), n):
                max_val = z[i - 1][j - 1]
                max_val = max(max_val, z[i][j - 1])
                if i + 1 < n:
                    max_val = max(max_val, z[i + 1][j - 1])
                z[i][j] += max_val

        return r + z[n - 2][n - 1] + z[n - 1][n - 2]
