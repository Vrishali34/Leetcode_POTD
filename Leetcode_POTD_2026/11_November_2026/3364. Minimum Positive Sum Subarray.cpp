class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), min_sum = INT_MAX;
        vector<int> pref_sum(n + 1, 0);
        for (int i = 0; i < n; i++) pref_sum[i + 1] = pref_sum[i] + nums[i];
        for (int i = 0; i < n; i++)
            for (int len = l; len <= r && i + len <= n; len++) {
                int cur_sum = pref_sum[i + len] - pref_sum[i];
                if (cur_sum > 0) min_sum = min(min_sum, cur_sum);
            }
        return min_sum == INT_MAX ? -1 : min_sum;
    }
};
