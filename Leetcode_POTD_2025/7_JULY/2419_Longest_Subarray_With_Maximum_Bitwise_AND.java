class Solution {
    public int longestSubarray(int[] nums) {
        int max_val = 0;
        for (int num : nums) {
            max_val = Math.max(max_val, num);
        }
        int max_len = 0;
        int current_len = 0;
        for (int num : nums) {
            if (num == max_val) {
                current_len++;
            } else {
                current_len = 0;
            }
            max_len = Math.max(max_len, current_len);
        }
        return max_len;
    }
}
