class Solution(object):
    def numOfSubarrays(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        v = z = 0
        w = 1
        mod = 1_000_000_007

        for y in arr:
            z += y
            v += z % 2
            w += 1 if z % 2 == 0 else 0

        return (v * w) % mod
