class Solution(object):
    def checkPowersOfThree(self, n):
        return n == 0 or (n % 3 != 2 and self.checkPowersOfThree(n // 3))
