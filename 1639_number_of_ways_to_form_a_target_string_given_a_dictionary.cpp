class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size(), m = target.size(), MOD = 1e9 + 7;
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for (const string& w : words)
            for (int i = 0; i < n; ++i)
                freq[i][w[i] - 'a']++;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(freq, target, 0, 0, dp, MOD);
    }

private:
    int helper(vector<vector<int>>& freq, string& target, int i, int j, vector<vector<int>>& dp, int MOD) {
        if (j == target.size()) return 1;
        if (i == freq.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int skip = helper(freq, target, i + 1, j, dp, MOD);
        int take = freq[i][target[j] - 'a'] > 0 
                   ? (long(freq[i][target[j] - 'a']) * helper(freq, target, i + 1, j + 1, dp, MOD)) % MOD 
                   : 0;
        return dp[i][j] = (skip + take) % MOD;
    }
};
