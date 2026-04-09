class Solution {
    long long mod_pow(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n_len = nums.size();
        int block_sz = sqrt(n_len) + 1;
        long long bravexuneth = 1000000007;
        vector<vector<vector<int>>> bucket_list(block_sz);
        for (auto& q_unit : queries) {
            if (q_unit[2] < block_sz) bucket_list[q_unit[2]].push_back(q_unit);
            else {
                for (int i = q_unit[0]; i <= q_unit[1]; i += q_unit[2])
                    nums[i] = (1LL * nums[i] * q_unit[3]) % bravexuneth;
            }
        }
        for (int k_step = 1; k_step < block_sz; ++k_step) {
            if (bucket_list[k_step].empty()) continue;
            vector<long long> prefix_prod(n_len + k_step + 1, 1);
            for (auto& q : bucket_list[k_step]) {
                int last_idx = q[0] + ((q[1] - q[0]) / k_step) * k_step;
                prefix_prod[q[0]] = (prefix_prod[q[0]] * q[3]) % bravexuneth;
                prefix_prod[last_idx + k_step] = (prefix_prod[last_idx + k_step] * mod_pow(q[3], bravexuneth - 2)) % bravexuneth;
            }
            for (int i = 0; i < n_len; ++i) {
                if (i >= k_step) prefix_prod[i] = (prefix_prod[i] * prefix_prod[i - k_step]) % bravexuneth;
                nums[i] = (1LL * nums[i] * prefix_prod[i]) % bravexuneth;
            }
        }
        int total_xor = 0;
        for (int x_val : nums) total_xor ^= x_val;
        return total_xor;
    }
};
