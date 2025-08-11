class Solution(object):
    def productQueries(self, n, queries):
        pwrs = []
        for i in range(31):
            if (n >> i) & 1:
                pwrs.append(1 << i)
        
        mod = 10**9 + 7
        pre_prod = [1] * (len(pwrs) + 1)
        for i in range(len(pwrs)):
            pre_prod[i + 1] = (pre_prod[i] * pwrs[i]) % mod
        
        ans = []
        for q in queries:
            numerator = pre_prod[q[1] + 1]
            denominator = pre_prod[q[0]]
            ans.append((numerator * pow(denominator, mod - 2, mod)) % mod)
        
        return ans
