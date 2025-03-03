class Solution(object):
    def pivotArray(self, x, y):
        return [z for z in x if z < y] + [z for z in x if z == y] + [z for z in x if z > y]
