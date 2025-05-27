class Solution(object):
    def differenceOfSums(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        # Version 1: Direct Iteration
        r = 0
        f = 0
        for p in range(1, n + 1):
            if p % m != 0:
                r += p
            else:
                f += p
        return r - f
