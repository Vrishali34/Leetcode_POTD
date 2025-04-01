class Solution {
    public long mostPoints(int[][] e) {
        int f = e.length;
        long[] g = new long[f + 1];
        for (int h = f - 1; h >= 0; --h)
            g[h] = Math.max(e[h][0] + ((h + e[h][1] + 1 < f) ? g[h + e[h][1] + 1] : 0), g[h + 1]);
        return g[0];
    }
}
