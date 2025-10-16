import java.util.Arrays;

class Solution {
    public int findSmallestInteger(int[] input_array, int modulus_base) {
        int[] remainder_counts = new int[modulus_base];
        for (long current_num : input_array) {
            int effective_remainder = (int) ((current_num % modulus_base + modulus_base) % modulus_base);
            remainder_counts[effective_remainder]++;
        }
        int max_consecutive = 0;
        while (remainder_counts[max_consecutive % modulus_base]-- > 0) max_consecutive++;
        return max_consecutive;
    }
}
