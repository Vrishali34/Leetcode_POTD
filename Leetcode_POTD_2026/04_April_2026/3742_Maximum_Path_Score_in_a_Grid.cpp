class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int r_lim = grid.size(), c_lim = grid[0].size();
        vector<vector<int>> curr_lyr(c_lim, vector<int>(k + 1, -1));
        curr_lyr[0][0] = 0;
        for (int r_idx = 0; r_idx < r_lim; ++r_idx) {
            vector<vector<int>> next_lyr(c_lim, vector<int>(k + 1, -1));
            for (int c_idx = 0; c_idx < c_lim; ++c_idx) {
                int val_wt = grid[r_idx][c_idx];
                int step_cost = (val_wt == 0) ? 0 : 1;
                for (int c_sum = step_cost; c_sum <= k; ++c_sum) {
                    int prev_max = -1;
                    if (r_idx > 0) prev_max = max(prev_max, curr_lyr[c_idx][c_sum - step_cost]);
                    if (c_idx > 0) prev_max = max(prev_max, next_lyr[c_idx - 1][c_sum - step_cost]);
                    if (r_idx == 0 && c_idx == 0 && c_sum == step_cost) prev_max = 0;
                    if (prev_max != -1) next_lyr[c_idx][c_sum] = prev_max + val_wt;
                }
            }
            curr_lyr = move(next_lyr);
        }
        int max_res = -1;
        for (int c_fin = 0; c_fin <= k; ++c_fin) max_res = max(max_res, curr_lyr[c_lim - 1][c_fin]);
        return max_res;
    }
};
