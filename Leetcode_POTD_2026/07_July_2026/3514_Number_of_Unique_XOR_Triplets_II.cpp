class Solution {
public:
    int uniqueXorTriplets(vector<int>& raw_nums) {
        vector<bool> pair_seen(2048, false), triad_seen(2048, false);
        int elem_cnt = raw_nums.size();
        for (int idx_a = 0; idx_a < elem_cnt; ++idx_a) {
            for (int idx_b = idx_a; idx_b < elem_cnt; ++idx_b) {
                pair_seen[raw_nums[idx_a] ^ raw_nums[idx_b]] = true;
            }
        }
        for (int pair_val = 0; pair_val < 2048; ++pair_val) {
            if (!pair_seen[pair_val]) continue;
            for (int num_val : raw_nums) {
                triad_seen[pair_val ^ num_val] = true;
            }
        }
        return count(triad_seen.begin(), triad_seen.end(), true);
    }
};
