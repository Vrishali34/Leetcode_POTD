class Solution(object):
    def makeFancyString(self, s):
        """
        :type s: str
        :rtype: str
        """
        astral_result = []
        last_orb = ''
        orb_count = 0

        for current_orb in s:
            if current_orb == last_orb:
                orb_count += 1
            else:
                last_orb = current_orb
                orb_count = 1

            if orb_count <= 2:
                astral_result.append(current_orb)
        return "".join(astral_result)
