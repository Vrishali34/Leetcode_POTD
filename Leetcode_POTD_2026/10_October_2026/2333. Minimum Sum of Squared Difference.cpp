class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> gap_vals(n);
        long long total_ops = (long long)k1 + k2;
        for (int idx = 0; idx < n; idx++)
            gap_vals[idx] = abs(nums1[idx] - nums2[idx]);

        long long lo_bound = 0, hi_bound = 100000;
        while (lo_bound < hi_bound) {
            long long mid_bound = lo_bound + (hi_bound - lo_bound) / 2;
            long long ops_needed = 0;
            for (long long gap_val : gap_vals)
                if (gap_val > mid_bound) ops_needed += gap_val - mid_bound;
            if (ops_needed <= total_ops) hi_bound = mid_bound;
            else lo_bound = mid_bound + 1;
        }

        long long cap_val = lo_bound, leftover_ops = total_ops;
        for (long long& gap_val : gap_vals)
            if (gap_val > cap_val) leftover_ops -= (gap_val - cap_val), gap_val = cap_val;

        sort(gap_vals.rbegin(), gap_vals.rend());
        int ptr = 0;
        while (leftover_ops > 0 && ptr < n && gap_vals[ptr] > 0) {
            gap_vals[ptr]--;
            leftover_ops--;
            ptr++;
            if (ptr == n || gap_vals[ptr] < gap_vals[ptr - 1]) ptr = 0;
        }

        long long result_sum = 0;
        for (long long gap_val : gap_vals)
            result_sum += gap_val * gap_val;
        return result_sum;
    }
};
