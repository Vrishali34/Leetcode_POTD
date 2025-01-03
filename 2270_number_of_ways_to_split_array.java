class Solution {
    public int waysToSplitArray(int[] p) {
        int q = p.length, r = 0;
        long s = 0, t = 0;
        for (int u : p) s += u;
        for (int v = 0; v < q - 1; v++) {
            t += p[v];
            if (2 * t >= s) r++;
        }
        return r;
    }
}
