class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int str_len = s.length();
        long long mod_val = 1e9 + 7;
        vector<int> fwd_nz(str_len, str_len), bwd_nz(str_len, -1), res_ans;
        vector<long long> cum_val = {0}, cum_sum = {0}, ten_pow = {1};
        long long active_val = 0, active_sum = 0, active_pow = 1;
        int nz_cnt = 0;
        for (int i = 0; i < str_len; ++i) {
            if (s[i] != '0') {
                int cur_dig = s[i] - '0';
                active_val = (active_val * 10 + cur_dig) % mod_val;
                active_sum += cur_dig;
                active_pow = (active_pow * 10) % mod_val;
                cum_val.push_back(active_val);
                cum_sum.push_back(active_sum);
                ten_pow.push_back(active_pow);
                nz_cnt++;
            }
            bwd_nz[i] = nz_cnt - 1;
        }
        int tracking_nz = nz_cnt;
        for (int i = str_len - 1; i >= 0; --i) {
            if (s[i] != '0') tracking_nz--;
            fwd_nz[i] = tracking_nz;
        }
        for (auto& qr : queries) {
            int left_bound = fwd_nz[qr[0]], right_bound = bwd_nz[qr[1]];
            if (left_bound > right_bound) {
                res_ans.push_back(0);
            } else {
                long long span = right_bound - left_bound + 1;
                long long segment_val = (cum_val[right_bound + 1] - cum_val[left_bound] * ten_pow[span]) % mod_val;
                if (segment_val < 0) segment_val += mod_val;
                long long segment_sum = cum_sum[right_bound + 1] - cum_sum[left_bound];
                res_ans.push_back((segment_val * (segment_sum % mod_val)) % mod_val);
            }
        }
        return res_ans;
    }
};
