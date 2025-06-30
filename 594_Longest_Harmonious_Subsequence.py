from collections import Counter

class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Use Counter to get the frequency of each number
        counts = Counter(nums)

        max_length = 0
        # Iterate through the unique numbers and their counts
        for num_val, num_count in counts.items():
            # Check if num_val + 1 exists in the counts
            if (num_val + 1) in counts:
                # If it does, calculate the combined length and update max_length
                max_length = max(max_length, num_count + counts[num_val + 1])
        
        return max_length
