class Solution {
    public int[] vowelStrings(String[] w, int[][] q) {
        final int v = 1 + (1 << ('e' - 'a')) + (1 << ('i' - 'a')) + (1 << ('o' - 'a')) + (1 << ('u' - 'a'));
        int n = w.length, m = q.length;
        int[] c = new int[n + 1];
        for (int i = 0; i < n; i++) 
            c[i + 1] = c[i] + (((1 << (w[i].charAt(0) - 'a')) & v) > 0 && ((1 << (w[i].charAt(w[i].length() - 1) - 'a')) & v) > 0 ? 1 : 0);
        int[] r = new int[m];
        for (int i = 0; i < m; i++) 
            r[i] = c[q[i][1] + 1] - c[q[i][0]];
        return r;
    }
}
