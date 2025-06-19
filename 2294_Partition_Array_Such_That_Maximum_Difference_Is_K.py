class Solution(object):
    def partitionArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        num_subsequences = 0
        i = 0
        n = len(nums)
        while i < n:
            num_subsequences += 1
            current_min = nums[i]
            while i < n and nums[i] - current_min <= k:
                i += 1
        return num_subsequences
