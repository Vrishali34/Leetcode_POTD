class Solution {
    public int longestNiceSubarray(int[] x) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < x.length; i++) {
            while ((a & x[i]) > 0) a ^= x[b++];
            a |= x[i];
            c = Math.max(c, i - b + 1);
        }
        return c;
    }
}
