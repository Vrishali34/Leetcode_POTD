class Solution(object):
    def longestSubarray(self, nums):
        z_c = 0
        l_p, m_l = 0, 0
        for r_p, n in enumerate(nums):
            if n == 0:
                z_c += 1
            while z_c > 1:
                if nums[l_p] == 0:
                    z_c -= 1
                l_p += 1
            m_l = max(m_l, r_p - l_p)
        return m_l
