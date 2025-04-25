class Solution(object):
    def countInterestingSubarrays(self, j, h, l):
        o = {0: 1}
        n, m = 0, 0
        for i in j:
            m += (i % h == l)
            n += o.get((m - l + h) % h, 0)
            o[(m % h)] = o.get((m % h), 0) + 1
        return n
