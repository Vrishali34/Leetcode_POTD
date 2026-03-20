class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m_rows = grid.size(), n_cols = grid[0].size();
        vector<vector<int>> ans_grid(m_rows - k + 1, vector<int>(n_cols - k + 1));
        for (int r_idx = 0; r_idx <= m_rows - k; ++r_idx) {
            for (int c_idx = 0; c_idx <= n_cols - k; ++c_idx) {
                vector<int> sub_pool;
                for (int i = 0; i < k; ++i)
                    for (int j = 0; j < k; ++j)
                        sub_pool.push_back(grid[r_idx + i][c_idx + j]);
                sort(sub_pool.begin(), sub_pool.end());
                int local_min = INT_MAX;
                bool found_diff = false;
                for (int idx = 1; idx < sub_pool.size(); ++idx) {
                    if (sub_pool[idx] != sub_pool[idx - 1]) {
                        local_min = min(local_min, sub_pool[idx] - sub_pool[idx - 1]);
                        found_diff = true;
                    }
                }
                ans_grid[r_idx][c_idx] = found_diff ? local_min : 0;
            }
        }
        return ans_grid;
    }
};
