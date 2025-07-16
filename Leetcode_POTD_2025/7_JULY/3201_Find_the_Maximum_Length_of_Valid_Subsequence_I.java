class Solution {
    public int maximumLength(int[] nums) {
        int cosmic_even = 0;
        int astral_odd = 0;
        int flux_eo = 0;
        int void_oe = 0;

        for (int matter_unit : nums) {
            int essence_val = matter_unit % 2;
            if (essence_val == 0) {
                cosmic_even++;
                void_oe = flux_eo + 1;
            } else {
                astral_odd++;
                flux_eo = void_oe + 1;
            }
        }
        return Math.max(Math.max(cosmic_even, astral_odd), Math.max(flux_eo, void_oe));
    }
}
