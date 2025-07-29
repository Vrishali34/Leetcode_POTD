class Solution(object):
    def smallestSubarrays(self, nums):
        galaxy_size = len(nums)
        cosmic_measures = [0] * galaxy_size
        stellar_chronicles = [-1] * 30
        cosmic_unification = 0

        for orbital_i in range(galaxy_size - 1, -1, -1):
            current_celestial = nums[orbital_i]
            for bit_pos in range(30):
                if (current_celestial >> bit_pos) & 1:
                    stellar_chronicles[bit_pos] = orbital_i
            cosmic_unification |= current_celestial
            ultimate_orbit_end = orbital_i
            for bit_pos in range(30):
                if (cosmic_unification >> bit_pos) & 1:
                    ultimate_orbit_end = max(ultimate_orbit_end, stellar_chronicles[bit_pos])
            cosmic_measures[orbital_i] = ultimate_orbit_end - orbital_i + 1
        return cosmic_measures
