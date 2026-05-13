class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int sz = nums.size();
        vector<int> delta_agg(2 * limit + 2, 0);
        for (int i = 0; i < sz / 2; ++i) {
            int val_a = nums[i], val_b = nums[sz - 1 - i];
            int low_bound = min(val_a, val_b) + 1;
            int high_bound = max(val_a, val_b) + limit;
            delta_agg[2] += 2;
            delta_agg[low_bound]--;
            delta_agg[val_a + val_b]--;
            delta_agg[val_a + val_b + 1]++;
            delta_agg[high_bound + 1]++;
        }
        int best_move = sz, flux_val = 0;
        for (int x = 2; x <= 2 * limit; ++x) {
            flux_val += delta_agg[x];
            best_move = min(best_move, flux_val);
        }
        return best_move;
    }
};
