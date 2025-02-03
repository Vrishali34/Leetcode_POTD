class Solution:
    def longestMonotonicSubarray(self, X):
        top, up, down = 1, 1, 1
        for j in range(1, len(X)):
            if X[j] > X[j-1]:
                up += 1
                down = 1
            elif X[j] < X[j-1]:
                down += 1
                up = 1
            else:
                up = down = 1
            top = max(top, up, down)
        return top
