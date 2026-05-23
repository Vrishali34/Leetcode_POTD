class Solution {
public:
    bool check(vector<int>& nums) {
        int drop_count = 0;
        int total_elements = nums.size();
        for (int idx = 0; idx < total_elements; ++idx) {
            if (nums[idx] > nums[(idx + 1) % total_elements]) {
                if (++drop_count > 1) return false;
            }
        }
        return true;
    }
};
