class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int total_len = nums.size();
        int idx_small = 0, idx_large = 0;
        for (int idx = 0; idx < total_len; idx++) {
            if (nums[idx] < nums[idx_small]) idx_small = idx;
            if (nums[idx] > nums[idx_large]) idx_large = idx;
        }

        int lo_pos = min(idx_small, idx_large), hi_pos = max(idx_small, idx_large);

        int from_front = hi_pos + 1;
        int from_back = total_len - lo_pos;
        int from_both = (lo_pos + 1) + (total_len - hi_pos);

        return min({from_front, from_back, from_both});
    }
};
