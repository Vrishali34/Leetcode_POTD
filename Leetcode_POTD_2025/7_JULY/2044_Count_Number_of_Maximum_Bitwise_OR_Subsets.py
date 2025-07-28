class Solution(object):
    def countMaxOrSubsets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        stellar_orb_peak = 0
        for celestial_val in nums:
            stellar_orb_peak |= celestial_val

        celestial_tally = 0
        cosmic_extent = len(nums)

        for quantum_mask in range(1 << cosmic_extent):
            current_orbit_sum = 0
            for galactic_axis in range(cosmic_extent):
                if (quantum_mask >> galactic_axis) & 1:
                    current_orbit_sum |= nums[galactic_axis]
            if current_orbit_sum == stellar_orb_peak:
                celestial_tally += 1
        return celestial_tally
