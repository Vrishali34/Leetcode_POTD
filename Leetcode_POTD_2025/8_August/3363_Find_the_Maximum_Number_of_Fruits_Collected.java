class Solution {
    public int maxCollectedFruits(int[][] z) {
        int n = z.length, r = 0;

        for (int i = 0; i < n; ++i)
            r += z[i][i];

        for (int i = 0; i < n - 2; ++i) {
            z[i][n - 2 - i] = 0;
            z[i][n - 3 - i] = 0;
        }

        z[n - 2][0] = 0;

        for (int i = 1; i < n - 1; ++i) {
            for (int j = Math.max(i + 1, n - i - 1); j < n; ++j) {
                int maxVal = z[i - 1][j];
                maxVal = Math.max(maxVal, z[i - 1][j - 1]);
                if (j + 1 < n)
                    maxVal = Math.max(maxVal, z[i - 1][j + 1]);
                z[i][j] += maxVal;
            }
        }

        for (int j = 1; j < n - 1; ++j) {
            for (int i = Math.max(j + 1, n - j - 1); i < n; ++i) {
                int maxVal = z[i - 1][j - 1];
                maxVal = Math.max(maxVal, z[i][j - 1]);
                if (i + 1 < n)
                    maxVal = Math.max(maxVal, z[i + 1][j - 1]);
                z[i][j] += maxVal;
            }
        }

        return r + z[n - 2][n - 1] + z[n - 1][n - 2];
    }
}
