class Solution {
public:
    int minimumCost(vector<int>& nums) {
        partial_sort(nums.begin() + 1, nums.begin() + 3, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
};
