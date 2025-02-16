class Solution {
    int[] z;
    boolean[] y;

    boolean f(int x, int n) {
        if (x == z.length) return true;
        if (z[x] != 0) return f(x + 1, n);
        for (int v = n; v > 0; v--) {
            if (y[v]) continue;
            int j = (v == 1) ? x : x + v;
            if (j >= z.length || z[j] != 0) continue;
            z[x] = z[j] = v;
            y[v] = true;
            if (f(x + 1, n)) return true;
            z[x] = z[j] = 0;
            y[v] = false;
        }
        return false;
    }

    public int[] constructDistancedSequence(int n) {
        z = new int[2 * n - 1];
        y = new boolean[n + 1];
        f(0, n);
        return z;
    }
}
