class Solution {
    public int mincostTickets(int[] t, int[] f) {
        int k = t.length, u = 0, v = 0;
        int[] w = new int[k];
        for (int e = 0; e < k; e++) {
            while (t[e] - t[u] >= 7) u++;
            while (t[e] - t[v] >= 30) v++;
            w[e] = Math.min((e > 0 ? w[e - 1] : 0) + f[0], 
                            Math.min((u > 0 ? w[u - 1] : 0) + f[1], 
                                     (v > 0 ? w[v - 1] : 0) + f[2]));
        }
        return w[k - 1];
    }
}
