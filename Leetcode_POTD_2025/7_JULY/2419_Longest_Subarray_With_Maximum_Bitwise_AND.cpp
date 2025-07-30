class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_num = 0;
        for(int num : nums) {
            max_num = max(max_num, num);
        }
        int max_len = 0;
        int current_len = 0;
        for(int num : nums) {
            if (num == max_num) {
                current_len++;
            } else {
                current_len = 0;
            }
            max_len = max(max_len, current_len);
        }
        return max_len;
    }
};
