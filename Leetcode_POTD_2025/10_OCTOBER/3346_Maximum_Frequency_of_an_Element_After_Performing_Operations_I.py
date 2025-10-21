class Solution:
    def maxFrequency(self,p,q,r):
        n=100003;f=[0]*n;h=[0]*n;x0=n;x1=0
        for v in p:
            f[v]+=1
            a,b=max(1,v-q),min(n-1,v+q+1)
            h[a]+=1;h[b]-=1
            x0=min(x0,a);x1=max(x1,b)
        s=y=0
        for i in range(x0,x1+1):
            s+=h[i];y=max(y,f[i]+min(s-f[i],r))
        return y
