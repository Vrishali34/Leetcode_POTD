class Solution {
public:
    int idealArrays(int n, int maxVal) {
        const int MOD = 1e9 + 7;
        const int MAX_LEN = 14;  // log2(10^4) ~ 14
        vector<vector<int>> divs(maxVal + 1);
        for (int i = 1; i <= maxVal; ++i)
            for (int j = i * 2; j <= maxVal; j += i)
                divs[j].push_back(i);

        vector<vector<long>> dp(MAX_LEN + 1, vector<long>(maxVal + 1));
        for (int i = 1; i <= maxVal; ++i) dp[1][i] = 1;

        for (int len = 2; len <= MAX_LEN; ++len)
            for (int v = 1; v <= maxVal; ++v)
                for (int d : divs[v])
                    dp[len][v] = (dp[len][v] + dp[len - 1][d]) % MOD;

        vector<long> ways(MAX_LEN + 1);
        for (int len = 1; len <= MAX_LEN; ++len)
            for (int v = 1; v <= maxVal; ++v)
                ways[len] = (ways[len] + dp[len][v]) % MOD;

        vector<long> fact(n + 1, 1), invf(n + 1, 1);
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
        for (int i = 1; i <= n; ++i) invf[i] = inv(fact[i], MOD);

        long res = 0;
        for (int len = 1; len <= MAX_LEN && len <= n; ++len) {
            long comb = fact[n - 1] * invf[len - 1] % MOD * invf[n - len] % MOD;
            res = (res + comb * ways[len]) % MOD;
        }
        return res;
    }

    long inv(long x, long mod) {
        long res = 1, p = mod - 2;
        while (p) {
            if (p & 1) res = res * x % mod;
            x = x * x % mod;
            p >>= 1;
        }
        return res;
    }
};
