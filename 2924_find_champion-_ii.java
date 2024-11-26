class Solution {
    public int findChampion(int n, int[][] edges) {
        int[] x = new int[n];
        for (int[] y : edges) x[y[1]]++;
        int v = -1, g = 0;
        for (int i = 0; i < n; i++) {
            if (x[i] == 0) {
                g++;
                v = i;
            }
            if (g > 1) return -1;
        }
        return v;
    }
}
