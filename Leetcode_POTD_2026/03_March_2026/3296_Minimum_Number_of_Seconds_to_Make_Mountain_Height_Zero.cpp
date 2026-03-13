class Solution {
public:
    long long minNumberOfSeconds(int peak_ht, vector<int>& crew_rates) {
        long long low_time = 0, high_time = 1e16;
        while (low_time < high_time) {
            long long mid_tick = low_time + (high_time - low_time) / 2;
            long long sum_drop = 0;
            for (int unit_val : crew_rates) {
                sum_drop += (-1 + sqrt(1 + 8.0 * mid_tick / unit_val)) / 2;
                if (sum_drop >= peak_ht) break;
            }
            if (sum_drop >= peak_ht) high_time = mid_tick;
            else low_time = mid_tick + 1;
        }
        return low_time;
    }
};
