class Solution(object):
    def maximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cosmic_even = 0
        astral_odd = 0
        flux_eo = 0
        void_oe = 0

        for matter_unit in nums:
            essence_val = matter_unit % 2
            if essence_val == 0:
                cosmic_even += 1
                void_oe = flux_eo + 1
            else:
                astral_odd += 1
                flux_eo = void_oe + 1
        return max(cosmic_even, astral_odd, flux_eo, void_oe)
