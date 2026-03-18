class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int row_max = grid.size(), col_max = grid[0].size(), valid_mats = 0;
        for (int r = 0; r < row_max; ++r) {
            for (int c = 0; c < col_max; ++c) {
                if (r > 0) grid[r][c] += grid[r - 1][c];
                if (c > 0) grid[r][c] += grid[r][c - 1];
                if (r > 0 && c > 0) grid[r][c] -= grid[r - 1][c - 1];
                if (grid[r][c] <= k) ++valid_mats;
                else break; 
            }
        }
        return valid_mats;
    }
};
