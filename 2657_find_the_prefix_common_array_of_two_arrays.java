class Solution {
    public int[] findThePrefixCommonArray(int[] x, int[] y) {
        int n = x.length, p = 0;
        int[] freq = new int[n + 1], res = new int[n];
        for (int i = 0; i < n; i++) {
            if (++freq[x[i]] == 2) p++;
            if (++freq[y[i]] == 2) p++;
            res[i] = p;
        }
        return res;
    }
}
