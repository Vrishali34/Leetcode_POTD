class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc_len = 1, dec_len = 1, max_len = 1;
        for (int i = 1; i < nums.size(); i++) {
            inc_len = nums[i] > nums[i - 1] ? inc_len + 1 : 1;
            dec_len = nums[i] < nums[i - 1] ? dec_len + 1 : 1;
            max_len = max(max_len, max(inc_len, dec_len));
        }
        return max_len;
    }
};
