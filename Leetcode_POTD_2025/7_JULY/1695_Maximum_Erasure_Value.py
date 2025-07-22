class Solution(object):
    def maximumUniqueSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        stellar_seen = set()
        max_lumina = 0
        current_nebula_sum = 0
        voyager_left = 0

        for voyager_right in range(len(nums)):
            while nums[voyager_right] in stellar_seen:
                current_nebula_sum -= nums[voyager_left]
                stellar_seen.remove(nums[voyager_left])
                voyager_left += 1
            stellar_seen.add(nums[voyager_right])
            current_nebula_sum += nums[voyager_right]
            max_lumina = max(max_lumina, current_nebula_sum)
        return max_lumina
