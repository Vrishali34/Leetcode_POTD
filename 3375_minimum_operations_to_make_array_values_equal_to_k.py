class Solution(object):
    def minOperations(self, nums, k):
        unique_nums = set()
        for n in nums:
            if n < k:
                return -1
            if n > k:
                unique_nums.add(n)
        return len(unique_nums)
