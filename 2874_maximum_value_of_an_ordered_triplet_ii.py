class Solution(object):
    def maximumTripletValue(self, x):
        n = len(x)
        right_max = [0] * n
        right_max[-1] = x[-1]
        for i in range(n - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], x[i])

        ans, left_max = 0, x[0]
        for j in range(1, n - 1):
            ans = max(ans, (left_max - x[j]) * right_max[j + 1])
            left_max = max(left_max, x[j])
        return ans
