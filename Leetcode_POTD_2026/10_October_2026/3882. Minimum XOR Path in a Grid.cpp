class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int row_cnt = grid.size(), col_cnt = grid[0].size();
        vector<vector<bitset<1024>>> reach(row_cnt, vector<bitset<1024>>(col_cnt));
        reach[0][0][grid[0][0]] = 1;

        for (int r = 0; r < row_cnt; r++) {
            for (int c = 0; c < col_cnt; c++) {
                if (!r && !c) continue;
                for (int x = 0; x < 1024; x++) {
                    int prev_val = x ^ grid[r][c];
                    if ((r && reach[r - 1][c][prev_val]) || (c && reach[r][c - 1][prev_val]))
                        reach[r][c][x] = 1;
                }
            }
        }

        for (int x = 0; x < 1024; x++)
            if (reach[row_cnt - 1][col_cnt - 1][x]) return x;
        return 0;
    }
};
