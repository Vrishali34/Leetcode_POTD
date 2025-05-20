class Solution {
    public boolean isZeroArray(int[] x, int[][] y) {
        int n = x.length;
        int[] z = new int[n + 1];
        for (int[] a : y) {
            z[a[0]]++;
            if (a[1] + 1 < z.length) z[a[1] + 1]--;
        }
        for (int i = 1; i < n; i++) z[i] += z[i - 1];
        for (int i = 0; i < n; i++) if (z[i] < x[i]) return false;
        return true;
    }
}
