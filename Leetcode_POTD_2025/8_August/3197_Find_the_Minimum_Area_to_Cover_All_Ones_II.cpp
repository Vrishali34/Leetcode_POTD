class Solution {
private:
    int get_box_area(const vector<vector<int>>& g, int r1, int c1, int r2, int c2) {
        int mr = 1e9, Mc = -1, mR = -1, mc = 1e9;
        bool found = false;
        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                if (g[i][j] == 1) {
                    mr = min(mr, i);
                    mc = min(mc, j);
                    mR = max(mR, i);
                    Mc = max(Mc, j);
                    found = true;
                }
            }
        }
        return found ? (mR - mr + 1) * (Mc - mc + 1) : 0;
    }
    
public:
    int minimumSum(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size(), min_val = 1e9;

        // Vert-Vert
        for (int c1 = 0; c1 < C - 1; ++c1)
            for (int c2 = c1 + 1; c2 < C; ++c2) {
                min_val = min(min_val, get_box_area(grid, 0, 0, R - 1, c1) +
                                       get_box_area(grid, 0, c1 + 1, R - 1, c2) +
                                       get_box_area(grid, 0, c2 + 1, R - 1, C - 1));
            }

        // Horiz-Horiz
        for (int r1 = 0; r1 < R - 1; ++r1)
            for (int r2 = r1 + 1; r2 < R; ++r2) {
                min_val = min(min_val, get_box_area(grid, 0, 0, r1, C - 1) +
                                       get_box_area(grid, r1 + 1, 0, r2, C - 1) +
                                       get_box_area(grid, r2 + 1, 0, R - 1, C - 1));
            }

        // Vert, then split one horizontally
        for (int c = 0; c < C - 1; ++c)
            for (int r = 0; r < R - 1; ++r) {
                min_val = min(min_val, get_box_area(grid, 0, 0, R - 1, c) +
                                       get_box_area(grid, 0, c + 1, r, C - 1) +
                                       get_box_area(grid, r + 1, c + 1, R - 1, C - 1));
                min_val = min(min_val, get_box_area(grid, 0, c + 1, R - 1, C - 1) +
                                       get_box_area(grid, 0, 0, r, c) +
                                       get_box_area(grid, r + 1, 0, R - 1, c));
            }
            
        // Horiz, then split one vertically
        for (int r = 0; r < R - 1; ++r)
            for (int c = 0; c < C - 1; ++c) {
                min_val = min(min_val, get_box_area(grid, 0, 0, r, C - 1) +
                                       get_box_area(grid, r + 1, 0, R - 1, c) +
                                       get_box_area(grid, r + 1, c + 1, R - 1, C - 1));
                min_val = min(min_val, get_box_area(grid, r + 1, 0, R - 1, C - 1) +
                                       get_box_area(grid, 0, 0, r, c) +
                                       get_box_area(grid, 0, c + 1, r, C - 1));
            }

        return min_val;
    }
};
