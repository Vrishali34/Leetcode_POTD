class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total_sum = 0;
        for (int elem_val : nums) total_sum += elem_val;
        long long target_sum = total_sum - x;
        if (target_sum < 0) return -1;
        if (target_sum == 0) return nums.size();

        int win_start = 0, best_len = -1;
        long long win_sum = 0;
        for (int win_end = 0; win_end < (int)nums.size(); win_end++) {
            win_sum += nums[win_end];
            while (win_sum > target_sum && win_start <= win_end) {
                win_sum -= nums[win_start];
                win_start++;
            }
            if (win_sum == target_sum)
                best_len = max(best_len, win_end - win_start + 1);
        }

        return best_len == -1 ? -1 : (int)nums.size() - best_len;
    }
};
