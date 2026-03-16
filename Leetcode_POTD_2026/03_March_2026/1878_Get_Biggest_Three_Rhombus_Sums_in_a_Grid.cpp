class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> peaks;
        int m = grid.size(), n = grid[0].size();
        auto add_val = [&](int val) {
            peaks.insert(val);
            if (peaks.size() > 3) peaks.erase(peaks.begin());
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                add_val(grid[i][j]);
                for (int sz = 1; i + 2 * sz < m && j - sz >= 0 && j + sz < n; ++sz) {
                    int s = grid[i][j] + grid[i + 2 * sz][j] + grid[i + sz][j - sz] + grid[i + sz][j + sz];
                    for (int k = 1; k < sz; ++k)
                        s += grid[i + k][j - k] + grid[i + k][j + k] + grid[i + 2 * sz - k][j - k] + grid[i + 2 * sz - k][j + k];
                    add_val(s);
                }
            }
        }
        return vector<int>(peaks.rbegin(), peaks.rend());
    }
};
