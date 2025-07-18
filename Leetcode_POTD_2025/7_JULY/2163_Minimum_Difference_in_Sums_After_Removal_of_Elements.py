import heapq

class Solution(object):
    def minimumDifference(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        temporal_n = len(nums) // 3
        bygone_min_sums = [0] * len(nums)
        vault_min_heap = []  # Python's heapq is a min-heap by default, so store negatives for max-heap behavior
        current_vault_sum = 0

        for i in range(2 * temporal_n):
            heapq.heappush(vault_min_heap, -nums[i]) # Store negative to simulate max-heap for smallest n elements
            current_vault_sum += nums[i]
            if len(vault_min_heap) > temporal_n:
                current_vault_sum += heapq.heappop(vault_min_heap) # Add back the negative (subtracting the original value)
            if len(vault_min_heap) == temporal_n:
                bygone_min_sums[i] = current_vault_sum

        future_max_sums = [0] * len(nums)
        abyss_max_heap = [] # Min-heap to find largest n elements
        current_abyss_sum = 0

        for i in range(len(nums) - 1, temporal_n - 1, -1): # Iterate backwards
            heapq.heappush(abyss_max_heap, nums[i])
            current_abyss_sum += nums[i]
            if len(abyss_max_heap) > temporal_n:
                current_abyss_sum -= heapq.heappop(abyss_max_heap)
            if len(abyss_max_heap) == temporal_n:
                future_max_sums[i] = current_abyss_sum

        cosmic_delta = float('inf')

        for k in range(temporal_n - 1, 2 * temporal_n):
            # Similar to Java, the checks `!= 0` are implicitly handled by the loop range and logic
            # for when values are assigned to the `_sums` arrays.
            if bygone_min_sums[k] != 0 and future_max_sums[k + 1] != 0:
                cosmic_delta = min(cosmic_delta, bygone_min_sums[k] - future_max_sums[k + 1])
        
        return cosmic_delta
