class Solution(object):
    def countSubarrays(self, a):
        z=0
        for i in range(len(a)-2):
            z+=2*(a[i]+a[i+2])==a[i+1]
        return z
