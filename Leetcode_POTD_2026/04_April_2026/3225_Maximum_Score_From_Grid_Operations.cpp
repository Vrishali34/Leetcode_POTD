
class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int grid_dim = grid.size();
        vector<vector<long long>> prefix_sums(grid_dim, vector<long long>(grid_dim + 1, 0));
        for (int c = 0; c < grid_dim; ++c) {
            for (int r = 0; r < grid_dim; ++r) {
                prefix_sums[c][r + 1] = prefix_sums[c][r] + grid[r][c];
            }
        }
        vector<long long> dec_peak(grid_dim + 1, 0), inc_peak(grid_dim + 1, 0);
        for (int j = 1; j < grid_dim; ++j) {
            vector<long long> next_dec(grid_dim + 1, 0), next_inc(grid_dim + 1, 0);
            for (int curr_h = 0; curr_h <= grid_dim; ++curr_h) {
                for (int prev_h = 0; prev_h <= grid_dim; ++prev_h) {
                    long long score_prev = (curr_h > prev_h) ? (prefix_sums[j - 1][curr_h] - prefix_sums[j - 1][prev_h]) : 0;
                    long long score_curr = (prev_h > curr_h) ? (prefix_sums[j][prev_h] - prefix_sums[j][curr_h]) : 0;
                    next_dec[curr_h] = max({next_dec[curr_h], score_prev + dec_peak[prev_h], inc_peak[prev_h]});
                    next_inc[curr_h] = max({next_inc[curr_h], score_curr + inc_peak[prev_h], score_curr + score_prev + dec_peak[prev_h]});
                }
            }
            dec_peak = next_dec;
            inc_peak = next_inc;
        }
        return *max_element(inc_peak.begin(), inc_peak.end());
    }
};
