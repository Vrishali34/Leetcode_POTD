class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long prefix_sum = 0;
        long long max_res = -1e17;
        vector<long long> min_sums(k, 1e17);
        min_sums[0] = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];
            int rem_idx = (i + 1) % k;
            
            if (min_sums[rem_idx] != 1e17) {
                max_res = max(max_res, prefix_sum - min_sums[rem_idx]);
            }
            min_sums[rem_idx] = min(min_sums[rem_idx], prefix_sum);
        }
        return max_res;
    }
};
