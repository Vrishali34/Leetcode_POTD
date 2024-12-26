class Solution(object):
    def findTargetSumWays(self, nums, target):
        memo = {}
        def dfs(i, t):
            if i == len(nums):
                return 1 if t == 0 else 0
            if (i, t) in memo:
                return memo[(i, t)]
            memo[(i, t)] = dfs(i + 1, t - nums[i]) + dfs(i + 1, t + nums[i])
            return memo[(i, t)]
        return dfs(0, target)
