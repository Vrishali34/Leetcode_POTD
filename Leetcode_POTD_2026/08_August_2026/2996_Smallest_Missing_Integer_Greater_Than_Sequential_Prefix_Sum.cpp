class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int prefixSum = nums[0];
        int i = 1;
        while (i < n && nums[i] == nums[i - 1] + 1) {
            prefixSum += nums[i];
            i++;
        }
        unordered_set<int> present(nums.begin(), nums.end());
        while (present.count(prefixSum)) prefixSum++;
        return prefixSum;
    }
};
