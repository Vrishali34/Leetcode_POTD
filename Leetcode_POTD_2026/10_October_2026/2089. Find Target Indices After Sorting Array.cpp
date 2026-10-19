class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less_cnt = 0, equal_cnt = 0;
        for (int curr_num : nums) {
            less_cnt += curr_num < target;
            equal_cnt += curr_num == target;
        }
        vector<int> target_idx_list(equal_cnt);
        iota(target_idx_list.begin(), target_idx_list.end(), less_cnt);
        return target_idx_list;
    }
};
