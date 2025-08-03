import bisect

class Solution(object):
    def maxTotalFruits(self, fruits, startPos, k):
        """
        :type fruits: List[List[int]]
        :type startPos: int
        :type k: int
        :rtype: int
        """
        # --- Solution 1: Binary search with prefix sums ---
        # Create a prefix sum list for efficient range sum queries
        n = len(fruits)
        prefix_sums = [0] * (n + 1)
        positions = [f[0] for f in fruits]
        for i in range(n):
            prefix_sums[i + 1] = prefix_sums[i] + fruits[i][1]
        
        max_harvest = 0
        
        def get_fruits_in_range(l, r):
            # Use bisect to find the indices of fruits within the range [l, r]
            start_idx = bisect.bisect_left(positions, l)
            end_idx = bisect.bisect_right(positions, r)
            return prefix_sums[end_idx] - prefix_sums[start_idx]
            
        # Case 1: Move left, then turn and move right
        # 'left_steps' is the distance moved to the left
        for left_steps in range(k + 1):
            # 'right_steps' is the remaining steps for the return trip to startPos and then right
            # The total steps are left_steps + left_steps + right_steps = k
            # So, right_steps = k - 2*left_steps
            right_steps = k - 2 * left_steps
            if right_steps < 0: continue
            max_harvest = max(max_harvest, get_fruits_in_range(startPos - left_steps, startPos + right_steps))
            
        # Case 2: Move right, then turn and move left
        # 'right_steps' is the distance moved to the right
        for right_steps in range(k + 1):
            # 'left_steps' is the remaining steps
            left_steps = k - 2 * right_steps
            if left_steps < 0: continue
            max_harvest = max(max_harvest, get_fruits_in_range(startPos - left_steps, startPos + right_steps))
            
        return max_harvest
