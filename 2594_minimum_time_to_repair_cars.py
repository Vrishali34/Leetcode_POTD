import math

class Solution(object):
    def repairCars(self, r, c):
        l, h = 0, min(r) * c * c
        while l < h:
            m = (l + h) // 2
            if sum(int(math.sqrt(m // i)) for i in r) >= c:
                h = m
            else:
                l = m + 1
        return l
