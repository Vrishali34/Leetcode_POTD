class Solution(object):
    def lengthAfterTransformations(self, s, t, nums):
        mod = 10**9+7
        B = 26
        f = [[0]*B for _ in range(B)]
        for i in range(B):
            for j in range(1, nums[i]+1):
                f[i][(i+j)%B] += 1
        def fxp(p, k):
            u = [[int(i==j) for j in range(B)] for i in range(B)]
            while k:
                if k&1:
                    u = [[sum(u[i][n]*p[n][j]%mod for n in range(B))%mod for j in range(B)] for i in range(B)]
                p = [[sum(p[i][n]*p[n][j]%mod for n in range(B))%mod for j in range(B)] for i in range(B)]
                k >>= 1
            return u
        T = fxp(f, t)
        a = [0]*B
        for ch in s:
            a[ord(ch)-97] += 1
        return sum(a[i]*sum(T[i])%mod for i in range(B))%mod
