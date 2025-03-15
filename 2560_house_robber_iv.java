class Solution {
    public int minCapability(int[] x, int y) {
        int l = 1, h = 1_000_000_000;
        while (l < h) {
            int m = (l + h) / 2, c = 0, i = 0;
            while (i < x.length) {
                if (x[i] <= m) { c++; i++; }
                i++;
            }
            if (c >= y) h = m;
            else l = m + 1;
        }
        return l;
    }
}
