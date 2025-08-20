class Solution(object):
    def countSquares(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        sky_depth = len(matrix)
        cosmic_span = len(matrix[0])
        total_luminosity = 0

        for celestial_r in range(sky_depth):
            for astral_c in range(cosmic_span):
                if matrix[celestial_r][astral_c] == 1:
                    if celestial_r > 0 and astral_c > 0:
                        stellar_left = matrix[celestial_r][astral_c - 1]
                        stellar_up = matrix[celestial_r - 1][astral_c]
                        stellar_diag = matrix[celestial_r - 1][astral_c - 1]
                        matrix[celestial_r][astral_c] = 1 + min(stellar_left, stellar_up, stellar_diag)
                    total_luminosity += matrix[celestial_r][astral_c]

        return total_luminosity
