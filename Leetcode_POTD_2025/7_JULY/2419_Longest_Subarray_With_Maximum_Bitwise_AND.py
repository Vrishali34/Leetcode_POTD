class Solution(object):
    def longestSubarray(self, nums):
        max_num = 0
        for num in nums:
            max_num = max(max_num, num)
        
        max_len = 0
        current_len = 0
        for num in nums:
            if num == max_num:
                current_len += 1
            else:
                current_len = 0
            max_len = max(max_len, current_len)
        
        return max_len
