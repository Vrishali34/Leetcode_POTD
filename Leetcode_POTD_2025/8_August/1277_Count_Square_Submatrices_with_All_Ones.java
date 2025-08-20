class Solution {
    public int countSquares(int[][] matrix) {
        int sky_depth = matrix.length;
        int cosmic_span = matrix[0].length;
        int total_luminosity = 0;

        for (int celestial_r = 0; celestial_r < sky_depth; celestial_r++) {
            for (int astral_c = 0; astral_c < cosmic_span; astral_c++) {
                if (matrix[celestial_r][astral_c] == 1) {
                    if (celestial_r > 0 && astral_c > 0) {
                        int stellar_left = matrix[celestial_r][astral_c - 1];
                        int stellar_up = matrix[celestial_r - 1][astral_c];
                        int stellar_diag = matrix[celestial_r - 1][astral_c - 1];
                        matrix[celestial_r][astral_c] = 1 + Math.min(Math.min(stellar_left, stellar_up), stellar_diag);
                    }
                    total_luminosity += matrix[celestial_r][astral_c];
                }
            }
        }
        return total_luminosity;
    }
}
