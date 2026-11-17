class Solution {
public:
    int minimumChanges(string s, int k) {
        int len = s.size();
        vector<vector<int>> cost_tbl(len, vector<int>(len, 0));
        for (int lo = 0; lo < len; lo++)
            for (int hi = lo + 1; hi < len; hi++) {
                int sub_len = hi - lo + 1, min_diff = INT_MAX;
                for (int step = 1; step < sub_len; step++) {
                    if (sub_len % step) continue;
                    int diff = 0;
                    for (int off = 0; off < step; off++)
                        for (int a = lo + off, b = hi - step + 1 + off; a < b; a += step, b -= step)
                            diff += s[a] != s[b];
                    min_diff = min(min_diff, diff);
                }
                cost_tbl[lo][hi] = min_diff;
            }

        vector<vector<int>> dp(k + 1, vector<int>(len + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int part = 1; part <= k; part++)
            for (int end = 2 * part; end <= len; end++)
                for (int start = 2 * (part - 1); start <= end - 2; start++)
                    dp[part][end] = min(dp[part][end], dp[part - 1][start] + cost_tbl[start][end - 1]);

        return dp[k][len];
    }
};
