#include <vector>

class Solution {
public:
    long long power_mod(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

    long long mod_inv(long long n_val) {
        return power_mod(n_val, 1000000007 - 2);
    }

    long long combinations_n_k(int n_total, int k_select) {
        if (k_select < 0 || k_select > n_total) return 0;
        if (k_select == 0 || k_select == n_total) return 1;
        if (k_select > n_total / 2) k_select = n_total - k_select;
        long long res_comb = 1;
        for (int i = 1; i <= k_select; ++i) {
            res_comb = (res_comb * (n_total - i + 1)) % 1000000007;
            res_comb = (res_comb * mod_inv(i)) % 1000000007;
        }
        return res_comb;
    }

    int countGoodArrays(int n, int m, int k) {
        long long MOD = 1e9 + 7;
        long long chosen_k_pos = combinations_n_k(n - 1, k);
        long long first_elm_ways = m;
        long long non_eq_pairs_ways = power_mod(m - 1, n - 1 - k);
        long long final_array_count = (chosen_k_pos * first_elm_ways) % MOD;
        final_array_count = (final_array_count * non_eq_pairs_ways) % MOD;
        return static_cast<int>(final_array_count);
    }
};
