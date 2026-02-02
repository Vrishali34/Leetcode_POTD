class Solution {
    long long toll_sum[100005];
    int toll_count[100005];
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int path_n = nums.size(), quota = k - 1;
        vector<int> fee_map = nums;
        sort(fee_map.begin(), fee_map.end());
        fee_map.erase(unique(fee_map.begin(), fee_map.end()), fee_map.end());
        int map_limit = fee_map.size();
        memset(toll_sum, 0, sizeof(toll_sum));
        memset(toll_count, 0, sizeof(toll_count));

        auto adjust_toll = [&](int rank, int val, int delta) {
            for (; rank <= map_limit; rank += rank & -rank) {
                toll_sum[rank] += val;
                toll_count[rank] += delta;
            }
        };

        long long best_extra = LLONG_MAX;
        int jump_step = 1 << (31 - __builtin_clz(map_limit));
        for (int i = 1; i < path_n; ++i) {
            int pos = lower_bound(fee_map.begin(), fee_map.end(), nums[i]) - fee_map.begin() + 1;
            adjust_toll(pos, nums[i], 1);
            if (i > dist + 1) {
                int exp_val = nums[i - dist - 1];
                int exp_pos = lower_bound(fee_map.begin(), fee_map.end(), exp_val) - fee_map.begin() + 1;
                adjust_toll(exp_pos, -exp_val, -1);
            }
            if (i >= quota) {
                int gate = 0, current_qty = 0; long long current_sum = 0;
                for (int p = jump_step; p > 0; p >>= 1) {
                    if (gate + p <= map_limit && current_qty + toll_count[gate + p] < quota) {
                        gate += p; current_qty += toll_count[gate]; current_sum += toll_sum[gate];
                    }
                }
                if (current_qty < quota) current_sum += (long long)(quota - current_qty) * fee_map[gate];
                best_extra = min(best_extra, current_sum);
            }
        }
        return nums[0] + best_extra;
    }
};
