class Solution(object):
    def putMarbles(self, q, k):
        p = sorted(q[i]+q[i+1] for i in range(len(q)-1))
        return sum(p[-1:-(k):-1]) - sum(p[:k-1])
