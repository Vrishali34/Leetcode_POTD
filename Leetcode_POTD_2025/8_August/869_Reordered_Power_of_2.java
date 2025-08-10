import java.util.Arrays;

class Solution {
    public boolean reorderedPowerOf2(int n) {
        int[] n_freq = countDigits(n);
        for (int i = 0; i < 31; i++) {
            int p_of_2 = 1 << i;
            if (p_of_2 > 1_000_000_000) break;
            if (Arrays.equals(n_freq, countDigits(p_of_2))) {
                return true;
            }
        }
        return false;
    }

    private int[] countDigits(int num) {
        int[] freq = new int[10];
        String s = String.valueOf(num);
        for (char c : s.toCharArray()) {
            freq[c - '0']++;
        }
        return freq;
    }
}
