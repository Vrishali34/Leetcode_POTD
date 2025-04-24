class Solution(object):
    def countCompleteSubarrays(self, n):
        u = len(set(n))
        a = 0
        for i in range(len(n)):
            s = set()
            for j in range(i, len(n)):
                s.add(n[j])
                if len(s) == u: a += 1
                if len(s) > u: break
        return a
