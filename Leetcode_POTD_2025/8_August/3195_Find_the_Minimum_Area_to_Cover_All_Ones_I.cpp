class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int r_min = 1001, c_min = 1001, r_max = -1, c_max = -1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    r_min = min(r_min, i);
                    c_min = min(c_min, j);
                    r_max = max(r_max, i);
                    c_max = max(c_max, j);
                }
            }
        }
        return (r_max - r_min + 1) * (c_max - c_min + 1);
    }
};
