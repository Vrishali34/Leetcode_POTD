class Solution(object):
    def countGood(self, a, b):
        z, q, m = 0, 0, collections.defaultdict(int)
        i = 0
        for j in range(len(a)):
            q += m[a[j]]
            m[a[j]] += 1
            while q >= b:
                m[a[i]] -= 1
                q -= m[a[i]]
                i += 1
            z += i
        return z
