class Solution(object):
    def numberOfAlternatingGroups(self, z, p):
        """
        :type z: List[int]
        :type p: int
        :rtype: int
        """
        r, t, n = 0, 1, len(z)
        for i in range(1, n + p - 1):
            t = 1 if z[i % n] == z[(i - 1) % n] else t + 1
            r += t >= p
        return r
