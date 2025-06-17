class Solution(object):
    def countGoodArrays(self, n, m, k):
        """
        :type n: int
        :type m: int
        :type k: int
        :rtype: int
        """
        MOD = 10**9 + 7

        def power(base, exp):
            res = 1
            base %= MOD
            while exp > 0:
                if exp % 2 == 1:
                    res = (res * base) % MOD
                base = (base * base) % MOD
                exp //= 2
            return res

        def mod_inverse(n_val):
            return power(n_val, MOD - 2)

        def combinations(n_total, k_select):
            if k_select < 0 or k_select > n_total:
                return 0
            if k_select == 0 or k_select == n_total:
                return 1
            if k_select > n_total // 2:
                k_select = n_total - k_select

            res_comb = 1
            for i in range(1, k_select + 1):
                res_comb = (res_comb * (n_total - i + 1)) % MOD
                res_comb = (res_comb * mod_inverse(i)) % MOD
            return res_comb

        chosen_k_pos = combinations(n - 1, k)
        first_elm_ways = m
        non_eq_pairs_ways = power(m - 1, n - 1 - k)

        final_array_count = (chosen_k_pos * first_elm_ways) % MOD
        final_array_count = (final_array_count * non_eq_pairs_ways) % MOD

        return final_array_count
