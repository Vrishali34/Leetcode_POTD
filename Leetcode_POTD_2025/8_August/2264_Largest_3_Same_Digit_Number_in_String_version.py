class Solution(object):
    def largestGoodInteger(self, num):
        for digit in range(9, -1, -1):
            triple = str(digit) * 3
            if triple in num:
                return triple
        return ""
