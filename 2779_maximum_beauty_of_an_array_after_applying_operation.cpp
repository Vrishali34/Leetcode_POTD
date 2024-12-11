class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size(), maxVal = 0;
        for (int i = 0; i < n; i++) maxVal = max(maxVal, nums[i]);
        vector<int> range(maxVal + 10, 0);
        for (int i = 0; i < n; i++) {
            int left = max(0, nums[i] - k);
            int right = min(maxVal, nums[i] + k) + 1;
            range[left]++;
            range[right]--;
        }
        int result = range[0];
        for (int i = 1; i < range.size(); i++) {
            range[i] += range[i - 1];
            result = max(result, range[i]);
        }
        return result;
    }
};
