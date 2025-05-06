class Solution {
    public int[] buildArray(int[] x) {
        int[] y = new int[x.length];
        for (int i = 0; i < x.length; i++) y[i] = x[x[i]];
        return y;
    }
}
