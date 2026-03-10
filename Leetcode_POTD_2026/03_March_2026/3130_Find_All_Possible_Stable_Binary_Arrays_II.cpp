class Solution {
public:
    int numberOfStableArrays(int zero_cnt, int one_cnt, int max_len) {
        long long mod_val = 1e9 + 7;
        vector<vector<vector<long long>>> bit_dp(zero_cnt + 1, vector<vector<long long>>(one_cnt + 1, vector<long long>(2, 0)));
        for (int i = 0; i <= min(zero_cnt, max_len); ++i) bit_dp[i][0][0] = 1;
        for (int j = 0; j <= min(one_cnt, max_len); ++j) bit_dp[0][j][1] = 1;

        for (int z = 1; z <= zero_cnt; ++z) {
            for (int o = 1; o <= one_cnt; ++o) {
                bit_dp[z][o][0] = (bit_dp[z - 1][o][0] + bit_dp[z - 1][o][1] - (z > max_len ? bit_dp[z - max_len - 1][o][1] : 0) + mod_val) % mod_val;
                bit_dp[z][o][1] = (bit_dp[z][o - 1][0] + bit_dp[z][o - 1][1] - (o > max_len ? bit_dp[z][o - max_len - 1][0] : 0) + mod_val) % mod_val;
            }
        }
        return (bit_dp[zero_cnt][one_cnt][0] + bit_dp[zero_cnt][one_cnt][1]) % mod_val;
    }
};
