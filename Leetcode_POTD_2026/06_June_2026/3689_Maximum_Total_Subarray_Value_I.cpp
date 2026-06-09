class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto [min_ptr, max_ptr] = minmax_element(nums.begin(), nums.end());
        long long span_val = *max_ptr - *min_ptr;
        return span_val * k;
    }
};
