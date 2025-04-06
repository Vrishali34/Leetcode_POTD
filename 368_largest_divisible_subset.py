class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []

        nums.sort()
        n = len(nums)
        dp = [1] * n
        prev = [-1] * n
        max_idx = 0

        for i in range(1, n):
            for j in range(i - 1, -1, -1):
                if nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
                    prev[i] = j
            if dp[i] > dp[max_idx]:
                max_idx = i

        result = []
        while max_idx >= 0:
            result.append(nums[max_idx])
            max_idx = prev[max_idx]

        return result[::-1]
