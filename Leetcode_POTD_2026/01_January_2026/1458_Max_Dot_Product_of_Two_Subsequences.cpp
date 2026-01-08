class Solution {
public:
    int maxDotProduct(vector<int>& v_one, vector<int>& v_two) {
        int sz_1 = v_one.size(), sz_2 = v_two.size();
        vector<int> cur_dp(sz_2 + 1, -1e9), pre_dp(sz_2 + 1, -1e9);
        for (int i = 1; i <= sz_1; ++i) {
            for (int j = 1; j <= sz_2; ++j) {
                int prod = v_one[i-1] * v_two[j-1];
                cur_dp[j] = max({prod, pre_dp[j-1] + prod, pre_dp[j], cur_dp[j-1]});
            }
            pre_dp = cur_dp;
        }
        return cur_dp[sz_2];
    }
};
