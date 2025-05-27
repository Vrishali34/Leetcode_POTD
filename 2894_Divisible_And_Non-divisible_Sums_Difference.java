class Solution {
    public int differenceOfSums(int n, int m) {
        
        int r = 0, f = 0;
        for (int p = 1; p <= n; ++p) {
            if (p % m != 0) r += p;
            else f += p;
        }
        return r - f;
    }
}
