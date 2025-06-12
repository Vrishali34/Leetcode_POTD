class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int big_diff = 0;
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            big_diff = max(big_diff, abs(nums[i] - nums[i+1]));
        }
        return max(big_diff, abs(nums.back() - nums.front()));
    }
};
