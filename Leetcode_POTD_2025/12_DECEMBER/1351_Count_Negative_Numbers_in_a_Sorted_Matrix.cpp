class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row_limit = grid.size(), col_limit = grid[0].size();
        int row_ptr = row_limit - 1, col_ptr = 0, minus_tally = 0;
        while (row_ptr >= 0 && col_ptr < col_limit) {
            if (grid[row_ptr][col_ptr] < 0) {
                minus_tally += col_limit - col_ptr;
                row_ptr--;
            } else {
                col_ptr++;
            }
        }
        return minus_tally;
    }
};
