class Solution {
    public long countSubarrays(int[] z, int k) {
        int m = 0, l = 0, c = 0;
        for (int n : z) m = Math.max(m, n);
        long q = 0;
        for (int r = 0; r < z.length; r++) {
            if (z[r] == m) c++;
            while (c >= k) {
                q += z.length - r;
                if (z[l++] == m) c--;
            }
        }
        return q;
    }
}
