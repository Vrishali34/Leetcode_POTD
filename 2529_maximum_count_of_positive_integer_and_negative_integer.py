class Solution:
    def maximumCount(self, nums):
        return max(len([x for x in nums if x > 0]), len([x for x in nums if x < 0]))
