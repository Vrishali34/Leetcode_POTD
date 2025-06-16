class Solution(object):
    def maximumDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_diff = -1
        min_so_far = nums[0]

        for k_idx in range(1, len(nums)):
            if nums[k_idx] > min_so_far:
                max_diff = max(max_diff, nums[k_idx] - min_so_far)
            min_so_far = min(min_so_far, nums[k_idx])
        return max_diff
