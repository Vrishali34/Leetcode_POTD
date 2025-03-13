class Solution(object):
    def minZeroArray(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: int
        """
        def canZero(nums, queries, k):
            n = len(nums)
            diff = [0] * (n + 1)
            temp = nums[:]
            
            for i in range(k):
                l, r, v = queries[i]
                diff[l] -= v
                diff[r + 1] += v
            
            curr = 0
            for i in range(n):
                curr += diff[i]
                temp[i] += curr
                if temp[i] > 0:
                    return False
            return True

        left, right, ans = 0, len(queries), -1
        while left <= right:
            mid = (left + right) // 2
            if canZero(nums, queries, mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans
