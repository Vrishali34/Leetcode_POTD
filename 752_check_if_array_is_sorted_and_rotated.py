class Solution(object):
    def check(self, nums):
        n = len(nums)
        count = 0
        for i in range(n):
            if nums[i] > nums[(i + 1) % n]:
                count += 1
            if count > 1:
                return False
        return True
