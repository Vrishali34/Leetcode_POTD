import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] productQueries(int n, int[][] queries) {
        List<Long> two_pows = new ArrayList<>();
        for (int i = 0; i < 31; ++i) {
            if (((n >> i) & 1) == 1) two_pows.add(1L << i);
        }

        long mod = 1000000007;
        long[] prefix_prods = new long[two_pows.size() + 1];
        prefix_prods[0] = 1;
        for (int i = 0; i < two_pows.size(); ++i) {
            prefix_prods[i + 1] = (prefix_prods[i] * two_pows.get(i)) % mod;
        }

        int[] res_array = new int[queries.length];
        for (int i = 0; i < queries.length; ++i) {
            long upper_prod = prefix_prods[queries[i][1] + 1];
            long lower_prod = prefix_prods[queries[i][0]];
            res_array[i] = (int) ((upper_prod * modular_inverse(lower_prod, mod)) % mod);
        }
        return res_array;
    }

    private long modular_inverse(long base, long mod) {
        return power_mod(base, mod - 2, mod);
    }

    private long power_mod(long base, long exp, long mod) {
        long result = 1;
        base %= mod;
        while (exp > 0) {
            if ((exp & 1) == 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
}
