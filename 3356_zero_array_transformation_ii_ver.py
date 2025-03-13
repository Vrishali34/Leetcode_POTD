class Solution(object):
    def minZeroArray(self, nums, queries):
        def apply_queries(k):
            n = len(nums)
            temp = nums[:]
            diff = [0] * (n + 1)

            for i in range(k):
                l, r, v = queries[i]
                diff[l] -= v
                if r + 1 < n:
                    diff[r + 1] += v

            curr = 0
            for i in range(n):
                curr += diff[i]
                temp[i] += curr
                if temp[i] > 0:
                    return False
            return True

        lo, hi, ans = 0, len(queries), -1
        while lo <= hi:
            mid = (lo + hi) // 2
            if apply_queries(mid):
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1

        return ans
