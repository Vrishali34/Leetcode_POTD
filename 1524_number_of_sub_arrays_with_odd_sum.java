class Solution {
    public int numOfSubarrays(int[] g) {
        long v = 0, z = 0, w = 1, mod = 1_000_000_007;
        for (int y : g) {
            z += y;
            v += z % 2;
            w += (z % 2 == 0) ? 1 : 0;
        }
        return (int) ((v * w) % mod);
    }
}
