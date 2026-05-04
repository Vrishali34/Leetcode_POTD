class Solution {
public:
    void rotate(vector<vector<int>>& grid_data) {
        int side_len = grid_data.size();
        for (int row_idx = 0; row_idx < side_len; ++row_idx) {
            for (int col_idx = row_idx + 1; col_idx < side_len; ++col_idx) {
                swap(grid_data[row_idx][col_idx], grid_data[col_idx][row_idx]);
            }
            reverse(grid_data[row_idx].begin(), grid_data[row_idx].end());
        }
    }
};
