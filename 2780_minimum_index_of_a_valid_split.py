class Solution(object):
    def minimumIndex(self, z):
        from collections import Counter
        n = len(z)
        c = Counter(z)
        for k, v in c.items():
            if v * 2 > n:
                d, t = k, v
                break
        x = 0
        for i in range(n - 1):
            if z[i] == d:
                x += 1
            if x * 2 > i + 1 and (t - x) * 2 > n - i - 1:
                return i
        return -1
