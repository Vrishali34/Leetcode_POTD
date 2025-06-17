class Solution {
    private static final int MOD = 1_000_000_007;

    private long power(long base, long exp) {
        long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    private long modInverse(long n) {
        return power(n, MOD - 2);
    }

    private long combinations(int n_total, int k_select) {
        if (k_select < 0 || k_select > n_total) return 0;
        if (k_select == 0 || k_select == n_total) return 1;
        if (k_select > n_total / 2) k_select = n_total - k_select;

        long res_comb = 1;
        for (int i = 1; i <= k_select; ++i) {
            res_comb = (res_comb * (n_total - i + 1)) % MOD;
            res_comb = (res_comb * modInverse(i)) % MOD;
        }
        return res_comb;
    }

    public int countGoodArrays(int n, int m, int k) {
        long chosenKPositions = combinations(n - 1, k);
        long firstElementWays = m;
        long nonEqualPairsWays = power(m - 1, n - 1 - k);

        long finalArrayCount = (chosenKPositions * firstElementWays) % MOD;
        finalArrayCount = (finalArrayCount * nonEqualPairsWays) % MOD;

        return (int) finalArrayCount;
    }
}
