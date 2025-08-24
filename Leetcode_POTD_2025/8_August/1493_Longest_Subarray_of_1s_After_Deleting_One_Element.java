class Solution {
    public int longestSubarray(int[] nums) {
        int z_c = 0;
        int l_p = 0;
        int m_l = 0;
        for (int r_p = 0; r_p < nums.length; r_p++) {
            if (nums[r_p] == 0) {
                z_c++;
            }
            while (z_c > 1) {
                if (nums[l_p] == 0) {
                    z_c--;
                }
                l_p++;
            }
            m_l = Math.max(m_l, r_p - l_p);
        }
        return m_l;
    }
}
