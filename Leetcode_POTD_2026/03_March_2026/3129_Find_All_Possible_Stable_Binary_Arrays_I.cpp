class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int r_mod = 1e9 + 7;
        vector<vector<vector<int>>> bit_grid(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));
        for (int i = 1; i <= min(zero, limit); ++i) bit_grid[i][0][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j) bit_grid[0][j][1] = 1;
        for (int z_idx = 1; z_idx <= zero; ++z_idx) {
            for (int o_idx = 1; o_idx <= one; ++o_idx) {
                long long way_0 = (0LL + bit_grid[z_idx - 1][o_idx][0] + bit_grid[z_idx - 1][o_idx][1]) % r_mod;
                if (z_idx > limit) way_0 = (way_0 - bit_grid[z_idx - limit - 1][o_idx][1] + r_mod) % r_mod;
                bit_grid[z_idx][o_idx][0] = way_0;
                long long way_1 = (0LL + bit_grid[z_idx][o_idx - 1][0] + bit_grid[z_idx][o_idx - 1][1]) % r_mod;
                if (o_idx > limit) way_1 = (way_1 - bit_grid[z_idx][o_idx - limit - 1][0] + r_mod) % r_mod;
                bit_grid[z_idx][o_idx][1] = way_1;
            }
        }
        return (bit_grid[zero][one][0] + bit_grid[zero][one][1]) % r_mod;
    }
};
