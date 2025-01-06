class Solution {
    public int[] minOperations(String b) {
        int n = b.length(), c = 0, s = 0;
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            r[i] += s;
            c += (b.charAt(i) == '1' ? 1 : 0);
            s += c;
        }
        c = s = 0;
        for (int i = n - 1; i >= 0; i--) {
            r[i] += s;
            c += (b.charAt(i) == '1' ? 1 : 0);
            s += c;
        }
        return r;
    }
}
