class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int row_count = grid.size(), col_count = grid[0].size();
        vector<vector<int>> cell_energy(row_count, vector<int>(col_count, 1e9));
        cell_energy[0][0] = 0;

        for (int jump_idx = 0; jump_idx <= k; ++jump_idx) {
            for (int r = 0; r < row_count; ++r) {
                for (int c = 0; c < col_count; ++c) {
                    if (r > 0) cell_energy[r][c] = min(cell_energy[r][c], cell_energy[r - 1][c] + grid[r][c]);
                    if (c > 0) cell_energy[r][c] = min(cell_energy[r][c], cell_energy[r][c - 1] + grid[r][c]);
                }
            }
            if (jump_idx == k) break;
            vector<int> value_threshold(10001, 1e9);
            for (int r = 0; r < row_count; ++r)
                for (int c = 0; c < col_count; ++c)
                    value_threshold[grid[r][c]] = min(value_threshold[grid[r][c]], cell_energy[r][c]);
            for (int v = 9999; v >= 0; --v) value_threshold[v] = min(value_threshold[v], value_threshold[v + 1]);
            for (int r = 0; r < row_count; ++r)
                for (int c = 0; c < col_count; ++c)
                    cell_energy[r][c] = min(cell_energy[r][c], value_threshold[grid[r][c]]);
        }
        return cell_energy[row_count - 1][col_count - 1];
    }
};
