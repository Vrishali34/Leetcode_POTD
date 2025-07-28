class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int stellar_orb_peak = 0;
        for (int celestial_val : nums) {
            stellar_orb_peak |= celestial_val;
        }

        int celestial_tally = 0;
        int cosmic_extent = nums.size();

        for (int quantum_mask = 0; quantum_mask < (1 << cosmic_extent); ++quantum_mask) {
            int current_orbit_sum = 0;
            for (int galactic_axis = 0; galactic_axis < cosmic_extent; ++galactic_axis) {
                if ((quantum_mask >> galactic_axis) & 1) {
                    current_orbit_sum |= nums[galactic_axis];
                }
            }
            if (current_orbit_sum == stellar_orb_peak) {
                celestial_tally++;
            }
        }
        return celestial_tally;
    }
};
