class Solution(object):
    def numRabbits(self, a):
        import collections
        d, s = collections.Counter(a), 0
        for x in d:
            s += -(-d[x] // (x + 1)) * (x + 1)
        return s
