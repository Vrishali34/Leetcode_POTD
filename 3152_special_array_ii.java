class Solution {
    public boolean[] isArraySpecial(int[] x, int[][] q) {
        int z = x.length;
        int[] p = new int[z];
        for (int i = 1; i < z; i++) 
            p[i] = p[i - 1] + ((x[i] % 2 == x[i - 1] % 2) ? 1 : 0);
        boolean[] r = new boolean[q.length];
        for (int i = 0; i < q.length; i++) 
            r[i] = p[q[i][1]] - (q[i][0] > 0 ? p[q[i][0]] : 0) == 0;
        return r;
    }
}
