class Solution(object):
    def kthSmallestProduct(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: int
        """
        
        def count_le(arr, val):
            """Counts elements <= val in arr"""
            low, high = 0, len(arr) - 1
            count = 0
            while low <= high:
                mid_idx = low + (high - low) // 2
                if arr[mid_idx] <= val:
                    count = mid_idx + 1
                    low = mid_idx + 1
                else:
                    high = mid_idx - 1
            return count

        def count_ge_idx(arr, val):
            """Finds index of first element >= val in arr"""
            low, high = 0, len(arr) - 1
            idx = len(arr)
            while low <= high:
                mid_idx = low + (high - low) // 2
                if arr[mid_idx] >= val:
                    idx = mid_idx
                    high = mid_idx - 1
                else:
                    low = mid_idx + 1
            return idx

        def custom_floor_div(dividend, divisor):
            res = dividend // divisor
            if (dividend % divisor != 0) and ((dividend < 0) != (divisor < 0)):
                res -= 1
            return res

        def custom_ceil_div(dividend, divisor):
            res = dividend // divisor
            if (dividend % divisor != 0) and ((dividend < 0) == (divisor < 0)):
                res += 1
            return res

        low = -10**10
        high = 10**10
        ans = 0

        while low <= high:
            mid_product_candidate = low + (high - low) // 2
            current_product_count = 0

            for n1 in nums1:
                if n1 == 0:
                    if mid_product_candidate >= 0:
                        current_product_count += len(nums2)
                elif n1 > 0:
                    target_n2_val = custom_floor_div(mid_product_candidate, n1)
                    current_product_count += count_le(nums2, target_n2_val)
                else: # n1 < 0
                    target_n2_val = custom_ceil_div(mid_product_candidate, n1)
                    current_product_count += (len(nums2) - count_ge_idx(nums2, target_n2_val))
            
            if current_product_count >= k:
                ans = mid_product_candidate
                high = mid_product_candidate - 1
            else:
                low = mid_product_candidate + 1
        
        return ans
