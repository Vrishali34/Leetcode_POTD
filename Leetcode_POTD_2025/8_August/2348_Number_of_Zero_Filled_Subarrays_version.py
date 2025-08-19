class Solution(object):
    def zeroFilledSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def calculate_void_count(array_of_numbers):
            void_total_sum = 0
            consecutive_voids = 0
            for singular_point in array_of_numbers:
                if singular_point == 0:
                    consecutive_voids += 1
                    void_total_sum += consecutive_voids
                else:
                    consecutive_voids = 0
            return void_total_sum
        
        return calculate_void_count(nums)
