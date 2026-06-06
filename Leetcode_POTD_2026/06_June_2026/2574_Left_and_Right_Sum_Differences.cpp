class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total_val = 0;
        for (int entry : nums) total_val += entry;
        
        int accumulated_left = 0;
        vector<int> absolute_diffs(nums.size());
        
        for (int idx = 0; idx < nums.size(); ++idx) {
            total_val -= nums[idx];
            absolute_diffs[idx] = abs(accumulated_left - total_val);
            accumulated_left += nums[idx];
        }
        return absolute_diffs;
    }
};
