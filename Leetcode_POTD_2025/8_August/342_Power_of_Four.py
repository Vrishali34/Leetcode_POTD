class Solution(object):
    def isPowerOfFour(self, n):
        if n <= 0:
            return False
        return (n & (n - 1) == 0) and (n % 3 == 1)
