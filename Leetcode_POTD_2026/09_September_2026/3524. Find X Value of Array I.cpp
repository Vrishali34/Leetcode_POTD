class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> mod_tally(k, 0), rem_count(k, 0);
        for (long long elem_val : nums) {
            vector<long long> next_tally(k, 0);
            int self_rem = elem_val % k;
            next_tally[self_rem]++;
            for (int prev_rem = 0; prev_rem < k; prev_rem++) {
                if (mod_tally[prev_rem])
                    next_tally[(prev_rem * elem_val) % k] += mod_tally[prev_rem];
            }
            mod_tally = next_tally;
            for (int rem_idx = 0; rem_idx < k; rem_idx++)
                rem_count[rem_idx] += mod_tally[rem_idx];
        }
        return rem_count;
    }
};
