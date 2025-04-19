class Solution {
    public long countFairPairs(int[] b, int p, int q) {
        Arrays.sort(b);
        return f(b, q) - f(b, p - 1);
    }
    long f(int[] y, int t) {
        long c = 0;
        for (int i = 0, j = y.length - 1; i < j; ++i) {
            while (i < j && y[i] + y[j] > t) j--;
            c += j - i;
        }
        return c;
    }
}
