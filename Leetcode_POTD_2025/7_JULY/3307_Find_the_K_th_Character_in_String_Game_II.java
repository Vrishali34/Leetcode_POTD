class Solution {
    public char kthCharacter(long k, int[] operations) {
        char prime_val = 'a';
        int phase_shift = 0;
        long current_span = 1;
        
        for (int op : operations) {
            current_span <<= 1;
        }

        for (int i = operations.length - 1; i >= 0; i--) {
            int morph_type = operations[i];
            current_span >>= 1;
            if (k > current_span) {
                k -= current_span;
                if (morph_type == 1) {
                    phase_shift++;
                }
            }
        }
        
        int final_char_code = prime_val + phase_shift;
        return (char) ('a' + (final_char_code - 'a') % 26);
    }
}
