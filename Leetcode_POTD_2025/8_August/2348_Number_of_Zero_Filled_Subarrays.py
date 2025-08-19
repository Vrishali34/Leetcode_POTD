class Solution(object):
    def zeroFilledSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total_subarrays = 0
        consecutive_zeros = 0
        for num in nums:
            if num == 0:
                consecutive_zeros += 1
                total_subarrays += consecutive_zeros
            else:
                consecutive_zeros = 0
        return total_subarrays
