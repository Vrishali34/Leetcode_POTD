class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int lastIdx = nums.size() - 1;
        return min({nums[lastIdx] - nums[2], nums[lastIdx - 1] - nums[1], nums[lastIdx - 2] - nums[0]});
    }
};
