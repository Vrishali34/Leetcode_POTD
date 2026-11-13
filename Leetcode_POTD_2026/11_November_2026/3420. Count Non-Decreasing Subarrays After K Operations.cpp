class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), right = n - 1;
        long long max_sum = 0, win_sum = 0, sub_count = 0;
        deque<int> rec_dq;
        for (int left = n - 1; left >= 0; left--) {
            win_sum += nums[left];
            while (!rec_dq.empty() && nums[rec_dq.front()] <= nums[left]) {
                int old_idx = rec_dq.front();
                rec_dq.pop_front();
                int seg_end = rec_dq.empty() ? right + 1 : rec_dq.front();
                max_sum -= (long long)nums[old_idx] * (seg_end - old_idx);
            }
            int seg_end = rec_dq.empty() ? right + 1 : rec_dq.front();
            max_sum += (long long)nums[left] * (seg_end - left);
            rec_dq.push_front(left);
            while (max_sum - win_sum > k) {
                win_sum -= nums[right];
                max_sum -= nums[rec_dq.back()];
                if (rec_dq.back() == right) rec_dq.pop_back();
                right--;
            }
            sub_count += right - left + 1;
        }
        return sub_count;
    }
};
