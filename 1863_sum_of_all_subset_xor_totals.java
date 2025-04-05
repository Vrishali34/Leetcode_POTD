class Solution {
    int s = 0;
    public int subsetXORSum(int[] x) {
        go(0, 0, x);
        return s;
    }
    void go(int i, int t, int[] x) {
        if (i == x.length) s += t;
        else { go(i + 1, t, x); go(i + 1, t ^ x[i], x); }
    }
}
