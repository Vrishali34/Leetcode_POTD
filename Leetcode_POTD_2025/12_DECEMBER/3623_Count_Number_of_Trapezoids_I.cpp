class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        long long final_tally = 0, accumulated_bases = 0;
        long long mod_val = 1e9 + 7;
        int num_pts = points.size();
        for (int i = 0; i < num_pts;) {
            int j = i;
            while (j < num_pts && points[j][1] == points[i][1]) j++;
            long long layer_cnt = j - i;
            if (layer_cnt >= 2) {
                long long current_bases = layer_cnt * (layer_cnt - 1) / 2;
                final_tally = (final_tally + (current_bases % mod_val) * accumulated_bases) % mod_val;
                accumulated_bases = (accumulated_bases + current_bases) % mod_val;
            }
            i = j;
        }
        return (int)final_tally;
    }
};
