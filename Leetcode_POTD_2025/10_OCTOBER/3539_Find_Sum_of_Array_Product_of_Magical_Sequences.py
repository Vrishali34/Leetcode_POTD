import collections

class Solution(object):
    def magicalSum(self, m, k, a):
        MOD = 10**9 + 7
        n = len(a)
        
        pwr = [[1] * (m + 1) for _ in range(n)]
        for i in range(n):
            for j in range(1, m + 1):
                pwr[i][j] = (a[i] * pwr[i][j - 1]) % MOD

        ncr_mat = collections.defaultdict(lambda: 0)
        for i in range(m + 1):
            ncr_mat[i, 0] = 1
            for j in range(1, i + 1):
                ncr_mat[i, j] = (ncr_mat[i - 1, j - 1] + ncr_mat[i - 1, j]) % MOD
        
        memo = {}

        def popcount(x):
            return bin(x).count('1')

        def solve(idx, carry, sz, cnt):
            if idx == n:
                if sz == m and cnt + popcount(carry) == k:
                    return 1
                return 0
            
            if cnt > k or sz > m:
                return 0

            state = (idx, carry, sz, cnt)
            if state in memo:
                return memo[state]

            ans = 0
            for c_i in range(m - sz + 1):
                
                product_term = pwr[idx][c_i]
                
                new_carry_val = carry + c_i
                bit_set = new_carry_val & 1
                next_carry = new_carry_val // 2
                
                recur_val = solve(
                    idx + 1, 
                    next_carry, 
                    sz + c_i, 
                    cnt + bit_set
                )
                
                term = (product_term * recur_val) % MOD
                term = (term * ncr_mat[m - sz, c_i]) % MOD
                
                ans = (ans + term) % MOD

            memo[state] = ans
            return ans

        return solve(0, 0, 0, 0)
