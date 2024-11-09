class Solution {
    public long minEnd(int n, int x) {
        long res = 0L;
        int m = 0, p = 0;
        for (long u = x, v = n - 1; m < 56; m++) {
            res |= ((u & (1L << m)) != 0 ? 1L : (v >> p++) & 1L) << m;
        }
        return res;
    }
}
