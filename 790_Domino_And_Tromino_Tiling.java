class Solution {
    public int numTilings(int p) {
        if (p == 1) return 1;
        if (p == 2) return 2;
        if (p == 3) return 5;
        int g = 1, h = 2, j = 5, k, m = 1000000007;
        for (int i = 4; i <= p; i++) {
            k = (int)((2L * j + g) % m);
            g = h; h = j; j = k;
        }
        return j;
    }
}
