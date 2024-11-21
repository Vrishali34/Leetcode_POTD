class Solution {
    public int countUnguarded(int m, int n, int[][] gd, int[][] wl) {
        int[][] gr = new int[m][n], d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int[] w : wl) gr[w[0]][w[1]] = -1;
        for (int[] g : gd) gr[g[0]][g[1]] = 2;
        for (int[] g : gd) {
            for (int[] k : d) {
                for (int i = g[0] + k[0], j = g[1] + k[1]; i >= 0 && j >= 0 && i < m && j < n && gr[i][j] != -1 && gr[i][j] != 2; i += k[0], j += k[1]) {
                    gr[i][j] = 1;
                }
            }
        }
        int c = 0;
        for (int[] r : gr) for (int v : r) if (v == 0) c++;
        return c;
    }
}
