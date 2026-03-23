class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int r_len = grid.size(), c_len = grid[0].size();
        vector<vector<long long>> hi(r_len, vector<long long>(c_len));
        vector<vector<long long>> lo(r_len, vector<long long>(c_len));
        hi[0][0] = lo[0][0] = grid[0][0];
        for (int i = 1; i < r_len; ++i) hi[i][0] = lo[i][0] = hi[i - 1][0] * grid[i][0];
        for (int j = 1; j < c_len; ++j) hi[0][j] = lo[0][j] = hi[0][j - 1] * grid[0][j];
        for (int i = 1; i < r_len; ++i) {
            for (int j = 1; j < c_len; ++j) {
                long long a = hi[i - 1][j] * grid[i][j], b = lo[i - 1][j] * grid[i][j];
                long long c = hi[i][j - 1] * grid[i][j], d = lo[i][j - 1] * grid[i][j];
                hi[i][j] = max({a, b, c, d});
                lo[i][j] = min({a, b, c, d});
            }
        }
        return hi[r_len - 1][c_len - 1] < 0 ? -1 : hi[r_len - 1][c_len - 1] % 1000000007;
    }
};
