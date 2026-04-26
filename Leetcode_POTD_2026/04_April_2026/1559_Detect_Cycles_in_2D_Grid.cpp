class Solution {
    int row_max, col_max;
    int move_x[4] = {0, 0, 1, -1}, move_y[4] = {1, -1, 0, 0};
public:
    bool trace_path(int r, int c, int pr, int pc, vector<vector<char>>& grid, vector<vector<bool>>& seen) {
        seen[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            int nr = r + move_x[i], nc = c + move_y[i];
            if (nr >= 0 && nr < row_max && nc >= 0 && nc < col_max && grid[nr][nc] == grid[r][c]) {
                if (seen[nr][nc]) {
                    if (nr != pr || nc != pc) return true;
                } else if (trace_path(nr, nc, r, c, grid, seen)) return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        row_max = grid.size(); col_max = grid[0].size();
        vector<vector<bool>> seen(row_max, vector<bool>(col_max, false));
        for (int i = 0; i < row_max; ++i)
            for (int j = 0; j < col_max; ++j)
                if (!seen[i][j] && trace_path(i, j, -1, -1, grid, seen)) return true;
        return false;
    }
};
