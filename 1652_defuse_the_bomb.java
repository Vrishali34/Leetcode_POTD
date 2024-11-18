class Solution {
    public int[] decrypt(int[] a, int b) {
        int c = a.length;
        int[] d = new int[c];
        if (b == 0) return d;
        int[] e = new int[c * 2];
        for (int i = 0; i < c; i++) e[i] = e[i + c] = a[i];
        for (int i = 0; i < c; i++) {
            int f = 0;
            for (int j = 1; j <= Math.abs(b); j++) 
                f += e[i + (b > 0 ? j : c - j)];
            d[i] = f;
        }
        return d;
    }
}
