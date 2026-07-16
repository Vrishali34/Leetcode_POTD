class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int elem_count = nums.size();
        vector<int> peak_gcd_trail(elem_count);
        int running_peak = 0;
        for (int idx = 0; idx < elem_count; idx++) {
            running_peak = max(running_peak, nums[idx]);
            peak_gcd_trail[idx] = __gcd(nums[idx], running_peak);
        }
        sort(peak_gcd_trail.begin(), peak_gcd_trail.end());
        long long paired_gcd_sum = 0;
        int low_ptr = 0, high_ptr = elem_count - 1;
        while (low_ptr < high_ptr) {
            paired_gcd_sum += __gcd(peak_gcd_trail[low_ptr], peak_gcd_trail[high_ptr]);
            low_ptr++;
            high_ptr--;
        }
        return paired_gcd_sum;
    }
};
