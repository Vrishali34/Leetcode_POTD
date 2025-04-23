class Solution(object):
    def countLargestGroup(self, n):
        d = [0] * 37
        for i in range(1, n + 1):
            s = sum(int(x) for x in str(i))
            d[s] += 1
        m = max(d)
        return d.count(m)
