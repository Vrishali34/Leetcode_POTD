class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long mod_val = 1e9 + 7;
        for (const auto& qry_vec : queries) {
            int cur_pos = qry_vec[0];
            while (cur_pos <= qry_vec[1]) {
                nums[cur_pos] = (1LL * nums[cur_pos] * qry_vec[3]) % mod_val;
                cur_pos += qry_vec[2];
            }
        }
        int res_xor = 0;
        for (int val_item : nums) res_xor ^= val_item;
        return res_xor;
    }
};
