class Solution {
    public long maxMatrixSum(int[][] a) {
        long t = 0, mn = Long.MAX_VALUE;
        int n = 0;
        for (int[] x : a) {
            for (int v : x) {
                t += Math.abs(v);
                mn = Math.min(mn, Math.abs((long) v));
                n += v < 0 ? 1 : 0;
            }
        }
        return n % 2 == 0 ? t : t - 2 * mn;
    }
}
