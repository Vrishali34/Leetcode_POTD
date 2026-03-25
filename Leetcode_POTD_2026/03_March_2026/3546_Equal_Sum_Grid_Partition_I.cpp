class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total_mass = 0;
        for (const auto& row_vec : grid)
            for (int val_unit : row_vec) total_mass += val_unit;
        if (total_mass % 2 != 0) return false;
        long long target_half = total_mass / 2, row_accum = 0;
        for (int r_idx = 0; r_idx < grid.size() - 1; ++r_idx) {
            for (int c_idx = 0; c_idx < grid[0].size(); ++c_idx) row_accum += grid[r_idx][c_idx];
            if (row_accum == target_half) return true;
        }
        long long col_accum = 0;
        for (int c_idx = 0; c_idx < grid[0].size() - 1; ++c_idx) {
            for (int r_idx = 0; r_idx < grid.size(); ++r_idx) col_accum += grid[r_idx][c_idx];
            if (col_accum == target_half) return true;
        }
        return false;
    }
};
