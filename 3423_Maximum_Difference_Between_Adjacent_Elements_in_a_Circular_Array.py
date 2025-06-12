class Solution(object):
    def maxAdjacentDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_diff = 0
        for i in range(len(nums) - 1):
            max_diff = max(max_diff, abs(nums[i] - nums[i+1]))
        return max(max_diff, abs(nums[-1] - nums[0]))
