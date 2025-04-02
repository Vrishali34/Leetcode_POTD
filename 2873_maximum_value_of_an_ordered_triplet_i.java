class Solution {
    public long maximumTripletValue(int[] z) {
        long mx = 0;
        int n = z.length;
        for (int x = 0; x < n; x++)
            for (int y = x + 1; y < n; y++)
                for (int w = y + 1; w < n; w++)
                    mx = Math.max(mx, (long) (z[x] - z[y]) * z[w]);
        return mx;
    }
}
