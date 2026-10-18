class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const long long mod_val = 1e9 + 7;
        int len_cnt = nums.size();
        vector<vector<long long>> pascal(len_cnt + 1, vector<long long>(len_cnt + 1, 1));
        for (int row_idx = 2; row_idx <= len_cnt; row_idx++)
            for (int col_idx = 1; col_idx < row_idx; col_idx++)
                pascal[row_idx][col_idx] = (pascal[row_idx - 1][col_idx - 1] + pascal[row_idx - 1][col_idx]) % mod_val;

        function<long long(vector<int>&)> countOrders = [&](vector<int>& seq) -> long long {
            int seq_len = seq.size();
            if (seq_len < 3) return 1;
            vector<int> small_part, big_part;
            for (int idx = 1; idx < seq_len; idx++)
                (seq[idx] < seq[0] ? small_part : big_part).push_back(seq[idx]);
            long long left_ways = countOrders(small_part), right_ways = countOrders(big_part);
            return pascal[seq_len - 1][small_part.size()] * left_ways % mod_val * right_ways % mod_val;
        };

        return (countOrders(nums) - 1 + mod_val) % mod_val;
    }
};
