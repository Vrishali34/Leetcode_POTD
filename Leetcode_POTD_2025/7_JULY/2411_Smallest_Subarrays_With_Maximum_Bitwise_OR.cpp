#include <vector>
#include <numeric> 
#include <algorithm> 


class Solution {
public:
    std::vector<int> smallestSubarrays(std::vector<int>& nums) {
        int galaxy_size = nums.size();
        std::vector<int> cosmic_measures(galaxy_size);
        std::vector<int> stellar_chronicles(30, -1);
        int cosmic_unification = 0;

        for (int orbital_i = galaxy_size - 1; orbital_i >= 0; --orbital_i) {
            int current_celestial = nums[orbital_i];
            for (int bit_pos = 0; bit_pos < 30; ++bit_pos) {
                if ((current_celestial >> bit_pos) & 1) {
                    stellar_chronicles[bit_pos] = orbital_i;
                }
            }
            cosmic_unification |= current_celestial;
            int ultimate_orbit_end = orbital_i;
            for (int bit_pos = 0; bit_pos < 30; ++bit_pos) {
                if ((cosmic_unification >> bit_pos) & 1) {
                    ultimate_orbit_end = std::max(ultimate_orbit_end, stellar_chronicles[bit_pos]);
                }
            }
            cosmic_measures[orbital_i] = ultimate_orbit_end - orbital_i + 1;
        }
        return cosmic_measures;
    }
};
