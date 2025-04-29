class Solution(object):
    def countSubarrays(self, a, k):
        m = max(a); l = c = res = 0
        for r in range(len(a)):
            c += a[r] == m
            while c >= k:
                res += len(a) - r
                c -= a[l] == m; l += 1
        return res
