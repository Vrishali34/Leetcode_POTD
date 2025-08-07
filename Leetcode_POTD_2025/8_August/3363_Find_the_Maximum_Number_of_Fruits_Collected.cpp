class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& z) {
        int n = z.size(), r = 0;
        for (int i = 0; i < n; ++i) r += z[i][i];
        for (int i = 0; i < n - 2; ++i) z[i][n - 2 - i] = z[i][n - 3 - i] = 0;
        z[n - 2][0] = 0;
        for (int i = 1; i < n - 1; ++i)
            for (int j = max(i + 1, n - i - 1); j < n; ++j)
                z[i][j] += max({z[i - 1][j], z[i - 1][j - 1], j + 1 < n ? z[i - 1][j + 1] : 0});
        for (int j = 1; j < n - 1; ++j)
            for (int i = max(j + 1, n - j - 1); i < n; ++i)
                z[i][j] += max({z[i - 1][j - 1], z[i][j - 1], i + 1 < n ? z[i + 1][j - 1] : 0});
        return r + z[n - 2][n - 1] + z[n - 1][n - 2];
    }
};
