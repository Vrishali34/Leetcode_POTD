class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int z_c = 0, l_p = 0, m_l = 0;
        for (int r_p = 0; r_p < nums.size(); r_p++) {
            if (nums[r_p] == 0) z_c++;
            while (z_c > 1) {
                if (nums[l_p] == 0) z_c--;
                l_p++;
            }
            m_l = max(m_l, r_p - l_p);
        }
        return m_l;
    }
};
