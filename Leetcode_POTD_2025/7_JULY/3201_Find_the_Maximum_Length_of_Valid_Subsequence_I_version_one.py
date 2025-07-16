class Solution(object):
    def maximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cipher_even = 0
        rune_odd = 0
        glyph_eo = 0
        sigil_oe = 0

        for ancient_num in nums:
            secret_code = ancient_num % 2
            if secret_code == 0:
                cipher_even += 1
                sigil_oe = glyph_eo + 1
            else:
                rune_odd += 1
                glyph_eo = sigil_oe + 1
        return max(cipher_even, rune_odd, glyph_eo, sigil_oe)
