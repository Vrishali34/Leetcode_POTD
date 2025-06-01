class Solution(object):
    def distributeCandies(self, n, limit):
        """
        :type n: int
        :type limit: int
        :rtype: int
        """
        yb = 0
        for x in range(limit + 1):
            rem = n - x
            if rem < 0:
                break
            min_y = max(0, rem - limit)
            max_y = min(limit, rem)
            if max_y >= min_y:
                yb += (max_y - min_y + 1)
        return yb
