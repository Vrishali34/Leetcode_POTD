class Solution {
    static final int MOD = 1_000_000_007;
    static final int MAXLEN = 14;

    public int idealArrays(int n, int maxValue) {
        List<Integer>[] divisors = new ArrayList[maxValue + 1];
        for (int i = 1; i <= maxValue; i++) divisors[i] = new ArrayList<>();
        for (int i = 1; i <= maxValue; i++) {
            for (int j = i * 2; j <= maxValue; j += i) {
                divisors[j].add(i);
            }
        }

        long[][] dp = new long[MAXLEN + 1][maxValue + 1];
        for (int i = 1; i <= maxValue; i++) dp[1][i] = 1;

        for (int len = 2; len <= MAXLEN; len++) {
            for (int v = 1; v <= maxValue; v++) {
                for (int d : divisors[v]) {
                    dp[len][v] = (dp[len][v] + dp[len - 1][d]) % MOD;
                }
            }
        }

        long[] totalWays = new long[MAXLEN + 1];
        for (int len = 1; len <= MAXLEN; len++) {
            for (int v = 1; v <= maxValue; v++) {
                totalWays[len] = (totalWays[len] + dp[len][v]) % MOD;
            }
        }

        long[] fact = new long[n + 1], invFact = new long[n + 1];
        fact[0] = invFact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
        for (int i = 1; i <= n; i++) invFact[i] = modInv(fact[i]);

        long res = 0;
        for (int len = 1; len <= Math.min(MAXLEN, n); len++) {
            long comb = fact[n - 1] * invFact[len - 1] % MOD * invFact[n - len] % MOD;
            res = (res + totalWays[len] * comb % MOD) % MOD;
        }

        return (int) res;
    }

    private long modInv(long x) {
        return pow(x, MOD - 2);
    }

    private long pow(long base, long exp) {
        long res = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    }
}
