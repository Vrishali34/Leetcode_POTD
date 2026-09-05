class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int total_len = nums.size();
        vector<int> pref_peak(total_len), suf_valley(total_len);
        
        pref_peak[0] = nums[0];
        for (int idx = 1; idx < total_len; idx++)
            pref_peak[idx] = max(pref_peak[idx - 1], nums[idx]);
        
        suf_valley[total_len - 1] = nums[total_len - 1];
        for (int idx = total_len - 2; idx >= 0; idx--)
            suf_valley[idx] = min(suf_valley[idx + 1], nums[idx]);
        
        for (int idx = 0; idx < total_len; idx++)
            if (pref_peak[idx] - suf_valley[idx] <= k)
                return idx;
        
        return -1;
    }
};
