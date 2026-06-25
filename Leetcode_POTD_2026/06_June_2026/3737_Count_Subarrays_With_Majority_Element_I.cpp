class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int valid_sub_cnt = 0;
        int array_sz = nums.size();
        for (int start_idx = 0; start_idx < array_sz; ++start_idx) {
            int target_bal = 0;
            for (int end_idx = start_idx; end_idx < array_sz; ++end_idx) {
                target_bal += (nums[end_idx] == target) ? 1 : -1;
                if (target_bal > 0) {
                    ++valid_sub_cnt;
                }
            }
        }
        return valid_sub_cnt;
    }
};
