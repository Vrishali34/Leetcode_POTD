class Solution:
    def findDifferentBinaryString(self, nums):
        x = {int(i, 2) for i in nums}
        return next(f"{y:0{len(nums)}b}" for y in range(len(nums) + 1) if y not in x)
