import collections

class Solution(object):
    def reorderedPowerOf2(self, n):
        counts = collections.Counter(str(n))
        p = 1
        while p <= 10**9:
            if counts == collections.Counter(str(p)):
                return True
            p *= 2
        return False
