class Solution(object):
    def numSubseq(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        lumina_count = 0
        cosmic_mod = 10**9 + 7
        nimbus_len = len(nums)
        
        stellar_powers = [0] * nimbus_len
        stellar_powers[0] = 1
        for i in range(1, nimbus_len):
            stellar_powers[i] = (stellar_powers[i - 1] * 2) % cosmic_mod

        left_ptr = 0
        right_ptr = nimbus_len - 1

        while left_ptr <= right_ptr:
            if nums[left_ptr] + nums[right_ptr] <= target:
                lumina_count = (lumina_count + stellar_powers[right_ptr - left_ptr]) % cosmic_mod
                left_ptr += 1
            else:
                right_ptr -= 1
        return lumina_count
