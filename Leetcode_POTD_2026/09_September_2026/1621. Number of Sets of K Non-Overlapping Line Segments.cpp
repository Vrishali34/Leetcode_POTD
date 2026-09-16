class Solution {
public:
    int numberOfSets(int n, int k) {
        const int mod_val = 1e9 + 7;
        vector<vector<vector<long long>>> dp_state(n, vector<vector<long long>>(k + 1, vector<long long>(2, 0)));

        dp_state[0][0][0] = 1;
        for (int pt_idx = 1; pt_idx < n; pt_idx++) {
            dp_state[pt_idx][0][0] = 1;
            for (int seg_cnt = 1; seg_cnt <= k; seg_cnt++) {
                dp_state[pt_idx][seg_cnt][0] = (dp_state[pt_idx - 1][seg_cnt][0] + dp_state[pt_idx - 1][seg_cnt][1]) % mod_val;
                dp_state[pt_idx][seg_cnt][1] = (dp_state[pt_idx - 1][seg_cnt][1] + dp_state[pt_idx - 1][seg_cnt - 1][0] + dp_state[pt_idx - 1][seg_cnt - 1][1]) % mod_val;
            }
        }

        return (dp_state[n - 1][k][0] + dp_state[n - 1][k][1]) % mod_val;
    }
};
