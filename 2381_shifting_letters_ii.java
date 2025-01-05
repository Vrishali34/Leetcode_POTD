class Solution {
    public String shiftingLetters(String r, int[][] m) {
        int n = r.length(), z = 0;
        int[] f = new int[n + 1];
        for (int[] q : m) {
            f[q[0]] += q[2] == 1 ? 1 : -1;
            f[q[1] + 1] -= q[2] == 1 ? 1 : -1;
        }
        for (int i = 0; i < n; ++i) f[i] = (z += f[i]) % 26;
        char[] x = r.toCharArray();
        for (int i = 0; i < n; ++i) x[i] = (char) ('a' + (x[i] - 'a' + (f[i] + 26) % 26) % 26);
        return new String(x);
    }
}
