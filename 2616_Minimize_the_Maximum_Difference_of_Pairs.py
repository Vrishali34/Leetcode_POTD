class Solution(object):
    def minimizeMax(self, nums, p):
        """
        :type nums: List[int]
        :type p: int
        :rtype: int
        """
        nums.sort()
        n = len(nums)
        low = 0
        high = nums[n - 1] - nums[0]
        min_max_diff = high

        while low <= high:
            mid = low + (high - low) // 2
            pairs_count = 0
            i = 0
            while i < n - 1:
                if nums[i+1] - nums[i] <= mid:
                    pairs_count += 1
                    i += 2
                else:
                    i += 1
            
            if pairs_count >= p:
                min_max_diff = mid
                high = mid - 1
            else:
                low = mid + 1
        
        return min_max_diff
