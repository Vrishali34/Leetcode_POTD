class Solution(object):
    def minCapability(self, nums, k):
        l, r = min(nums), max(nums)
        while l < r:
            m, c, i = (l + r) // 2, 0, 0
            while i < len(nums):
                if nums[i] <= m:
                    c += 1
                    i += 1
                i += 1
            if c >= k:
                r = m
            else:
                l = m + 1
        return l
