import java.util.Arrays;

class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int galaxy_size = nums.length;
        int[] cosmic_measures = new int[galaxy_size];
        int[] stellar_chronicles = new int[30];
        Arrays.fill(stellar_chronicles, -1);
        int cosmic_unification = 0;

        for (int orbital_i = galaxy_size - 1; orbital_i >= 0; --orbital_i) {
            int current_celestial = nums[orbital_i];
            for (int bit_pos = 0; bit_pos < 30; ++bit_pos) {
                if (((current_celestial >> bit_pos) & 1) == 1) {
                    stellar_chronicles[bit_pos] = orbital_i;
                }
            }
            cosmic_unification |= current_celestial;
            int ultimate_orbit_end = orbital_i;
            for (int bit_pos = 0; bit_pos < 30; ++bit_pos) {
                if (((cosmic_unification >> bit_pos) & 1) == 1) {
                    ultimate_orbit_end = Math.max(ultimate_orbit_end, stellar_chronicles[bit_pos]);
                }
            }
            cosmic_measures[orbital_i] = ultimate_orbit_end - orbital_i + 1;
        }
        return cosmic_measures;
    }
}
