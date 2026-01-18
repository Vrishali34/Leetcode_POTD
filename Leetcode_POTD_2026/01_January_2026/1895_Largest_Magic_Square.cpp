class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int r_limit = grid.size(), c_limit = grid[0].size();
        vector<vector<int>> r_sum(r_limit, vector<int>(c_limit + 1, 0));
        vector<vector<int>> c_sum(c_limit, vector<int>(r_limit + 1, 0));
        for (int i = 0; i < r_limit; ++i)
            for (int j = 0; j < c_limit; ++j) {
                r_sum[i][j + 1] = r_sum[i][j] + grid[i][j];
                c_sum[j][i + 1] = c_sum[j][i] + grid[i][j];
            }
        for (int k = min(r_limit, c_limit); k > 1; --k)
            for (int i = 0; i <= r_limit - k; ++i)
                for (int j = 0; j <= c_limit - k; ++j) {
                    int target_val = r_sum[i][j + k] - r_sum[i][j];
                    bool is_magic = true;
                    for (int r = 1; r < k; ++r)
                        if (r_sum[i + r][j + k] - r_sum[i + r][j] != target_val) { is_magic = false; break; }
                    if (!is_magic) continue;
                    for (int c = 0; c < k; ++c)
                        if (c_sum[j + c][i + k] - c_sum[j + c][i] != target_val) { is_magic = false; break; }
                    if (!is_magic) continue;
                    int d1 = 0, d2 = 0;
                    for (int d = 0; d < k; ++d) {
                        d1 += grid[i + d][j + d];
                        d2 += grid[i + d][j + k - 1 - d];
                    }
                    if (d1 == target_val && d2 == target_val) return k;
                }
        return 1;
    }
};
