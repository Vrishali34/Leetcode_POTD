class Solution {
    public int minimumSize(int[] p, int q) {
        int s = 1, e = Arrays.stream(p).max().getAsInt();
        while (s < e) {
            int m = (s + e) >> 1, v = 0;
            for (int k : p) v += (k - 1) / m;
            if (v > q) s = m + 1; else e = m;
        }
        return s;
    }
}
