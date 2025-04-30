class Solution(object):
    def findNumbers(self, z):
        return sum(1 for y in z if len(str(y)) & 1 == 0)
