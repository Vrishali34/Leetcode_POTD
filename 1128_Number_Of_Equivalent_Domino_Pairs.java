class Solution {
    public int numEquivDominoPairs(int[][] z) {
        int[] a = new int[100];
        int r = 0;
        for (int[] x : z) {
            int k = Math.min(x[0], x[1]) * 10 + Math.max(x[0], x[1]);
            r += a[k]++;
        }
        return r;
    }
}
