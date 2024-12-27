class Solution(object):
    def maxScoreSightseeingPair(self, v):
        max_sum, max_prev = 0, v[0]
        for i in range(1, len(v)):
            max_sum = max(max_sum, max_prev + v[i] - i)
            max_prev = max(max_prev, v[i] + i)
        return max_sum
