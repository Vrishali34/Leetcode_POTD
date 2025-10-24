class Solution {
    public int nextBeautifulNumber(int n) {
        for (int m = n + 1; m < 10000000; m++) {
            int[] d_counts = new int[7];
            int temp_m = m;
            boolean is_balanced = true;
            while (temp_m > 0) {
                int d = temp_m % 10;
                if (d == 0 || d > 6) {
                    is_balanced = false;
                    break;
                }
                d_counts[d]++;
                temp_m /= 10;
            }
            if (!is_balanced) continue;
            for (int d = 1; d <= 6; d++) {
                if (d_counts[d] > 0 && d_counts[d] != d) {
                    is_balanced = false;
                    break;
                }
            }
            if (is_balanced) return m;
        }
        return -1;
    }
}
