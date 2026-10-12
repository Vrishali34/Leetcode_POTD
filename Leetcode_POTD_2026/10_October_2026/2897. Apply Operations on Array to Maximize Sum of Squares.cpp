class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int bit_freq[32] = {0};

        for (int cur_val : nums)
            for (int bit_pos = 0; bit_pos < 32; bit_pos++)
                if (cur_val & (1 << bit_pos))
                    bit_freq[bit_pos]++;

        long long total_sum = 0;
        for (int pick_idx = 0; pick_idx < k; pick_idx++) {
            long long built_val = 0;
            for (int bit_pos = 0; bit_pos < 32; bit_pos++)
                if (bit_freq[bit_pos]-- > 0)
                    built_val |= (1LL << bit_pos);
            total_sum = (total_sum + (built_val % MOD) * (built_val % MOD)) % MOD;
        }

        return (int)total_sum;
    }
};
