class Solution {
public:
    long long countFairPairs(vector<int>& nums, int minV, int maxV) {
        long long count = 0;
        sort(nums.begin(), nums.end());
        for (int idx = 0; idx < nums.size() - 1; idx++) {
            auto high = upper_bound(nums.begin() + idx + 1, nums.end(), maxV - nums[idx]);
            auto low = lower_bound(nums.begin() + idx + 1, nums.end(), minV - nums[idx]);
            count += (high - low);
        }
        return count;
    }
};
