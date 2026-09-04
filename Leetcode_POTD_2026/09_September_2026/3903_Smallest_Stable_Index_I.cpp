class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int total_len = nums.size();
        vector<int> prefix_peak(total_len), suffix_valley(total_len);

        prefix_peak[0] = nums[0];
        for (int idx = 1; idx < total_len; idx++)
            prefix_peak[idx] = max(prefix_peak[idx - 1], nums[idx]);

        suffix_valley[total_len - 1] = nums[total_len - 1];
        for (int idx = total_len - 2; idx >= 0; idx--)
            suffix_valley[idx] = min(suffix_valley[idx + 1], nums[idx]);

        for (int idx = 0; idx < total_len; idx++)
            if (prefix_peak[idx] - suffix_valley[idx] <= k)
                return idx;

        return -1;
    }
};
