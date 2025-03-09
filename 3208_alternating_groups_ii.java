class Solution {
    public int numberOfAlternatingGroups(int[] x, int y) {
        int z = 0, c = 1, d = x.length;
        for (int i = 1; i < d + y - 1; i++) {
            c = ((x[i % d] ^ x[(i - 1) % d]) == 1) ? c + 1 : 1;
            z += (c >= y) ? 1 : 0;
        }
        return z;
    }
}
