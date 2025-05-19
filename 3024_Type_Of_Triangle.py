class Solution(object):
    def triangleType(self, z):
        z.sort()
        return "none" if z[0] + z[1] <= z[2] else "equilateral" if z[0] == z[2] else "isosceles" if z[0] == z[1] or z[1] == z[2] else "scalene"
