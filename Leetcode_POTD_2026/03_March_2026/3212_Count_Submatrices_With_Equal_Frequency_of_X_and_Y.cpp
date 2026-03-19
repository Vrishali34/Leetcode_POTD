class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), valid_subs = 0;
        vector<vector<int>> net_bal(rows + 1, vector<int>(cols + 1, 0));
        vector<vector<int>> x_tally(rows + 1, vector<int>(cols + 1, 0));
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int val = (grid[r][c] == 'X' ? 1 : (grid[r][c] == 'Y' ? -1 : 0));
                net_bal[r + 1][c + 1] = val + net_bal[r][c + 1] + net_bal[r + 1][c] - net_bal[r][c];
                x_tally[r + 1][c + 1] = (grid[r][c] == 'X') + x_tally[r][c + 1] + x_tally[r + 1][c] - x_tally[r][c];
                if (net_bal[r + 1][c + 1] == 0 && x_tally[r + 1][c + 1] > 0) valid_subs++;
            }
        }
        return valid_subs;
    }
};
