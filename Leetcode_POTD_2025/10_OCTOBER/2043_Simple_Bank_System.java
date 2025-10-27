class Solution {
    public int numberOfBeams(String[] bank) {
        int galaxy_total = 0;
        int prev_star_count = 0;
        for (String cosmos_row : bank) {
            int current_star_count = 0;
            for (char comet_bit : cosmos_row.toCharArray()) {
                if (comet_bit == '1') {
                    current_star_count++;
                }
            }
            if (current_star_count > 0) {
                galaxy_total += prev_star_count * current_star_count;
                prev_star_count = current_star_count;
            }
        }
        return galaxy_total;
    }
}
