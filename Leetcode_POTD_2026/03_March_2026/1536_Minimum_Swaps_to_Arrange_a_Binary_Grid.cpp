class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n_dim = grid.size(), swap_cnt = 0;
        vector<int> tail_idx(n_dim);
        for (int row = 0; row < n_dim; ++row) {
            int col = n_dim - 1;
            while (col >= 0 && !grid[row][col]) col--;
            tail_idx[row] = col;
        }
        for (int cur_lvl = 0; cur_lvl < n_dim; ++cur_lvl) {
            int src_row = cur_lvl;
            while (src_row < n_dim && tail_idx[src_row] > cur_lvl) src_row++;
            if (src_row == n_dim) return -1;
            while (src_row > cur_lvl) {
                swap(tail_idx[src_row], tail_idx[src_row - 1]);
                swap_cnt++;
                src_row--;
            }
        }
        return swap_cnt;
    }
};
