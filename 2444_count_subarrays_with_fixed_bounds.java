class Solution {
    public long countSubarrays(int[] v, int p, int q) {
        long z = 0;
        int a = -1, b = -1, c = -1;
        for (int i = 0; i < v.length; ++i) {
            if (v[i] < p || v[i] > q) c = i;
            if (v[i] == p) a = i;
            if (v[i] == q) b = i;
            z += Math.max(0, Math.min(a, b) - c);
        }
        return z;
    }
}
