class Solution(object):
    def subsetXORSum(self, b):
        n, s = len(b), 0
        for i in range(1 << n):
            x = 0
            for j in range(n):
                if i & (1 << j): x ^= b[j]
            s += x
        return s
