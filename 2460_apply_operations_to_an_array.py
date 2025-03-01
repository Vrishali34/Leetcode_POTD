class Solution(object):
    def applyOperations(self, x):
        n, y = len(x), []
        for i in range(n - 1):
            if x[i] and x[i] == x[i + 1]:
                x[i], x[i + 1] = x[i] * 2, 0
        return [i for i in x if i] + [0] * x.count(0)
