class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int arr_len = nums.size();
        long long total_sum = 0;

        for (int start_idx = 0; start_idx < arr_len; start_idx++) {
            unordered_set<int> seen_vals;
            for (int end_idx = start_idx; end_idx < arr_len; end_idx++) {
                seen_vals.insert(nums[end_idx]);
                long long distinct_cnt = seen_vals.size();
                total_sum += distinct_cnt * distinct_cnt;
            }
        }

        return (int)total_sum;
    }
};
