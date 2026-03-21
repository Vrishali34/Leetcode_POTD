class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int row_top = x, row_bot = x + k - 1;
        while (row_top < row_bot) {
            for (int col_idx = y; col_idx < y + k; ++col_idx) {
                swap(grid[row_top][col_idx], grid[row_bot][col_idx]);
            }
            row_top++;
            row_bot--;
        }
        return grid;
    }
};
