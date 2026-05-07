class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n_len = nums.size();
        vector<int> res_vals(n_len), r_min(n_len);
        r_min[n_len - 1] = nums[n_len - 1];
        for (int i = n_len - 2; i >= 0; --i) r_min[i] = min(nums[i], r_min[i + 1]);
        int cur_max = 0, start_ptr = 0;
        for (int i = 0; i < n_len; ++i) {
            cur_max = max(cur_max, nums[i]);
            if (i == n_len - 1 || cur_max <= r_min[i + 1]) {
                fill(res_vals.begin() + start_ptr, res_vals.begin() + i + 1, cur_max);
                start_ptr = i + 1;
                cur_max = 0;
            }
        }
        return res_vals;
    }
};
