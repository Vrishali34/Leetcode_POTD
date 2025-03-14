class Solution(object):
    def maximumCandies(self, candies, k):
        if sum(candies) < k:
            return 0
        l, r = 1, sum(candies) // k
        while l < r:
            m = (l + r + 1) // 2
            if sum(x // m for x in candies) < k:
                r = m - 1
            else:
                l = m
        return l
