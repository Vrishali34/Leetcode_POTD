class Solution {
    public int minimumRecolors(String x, int y) {
        int a = 0, b = 0;
        for (int i = 0; i < y; i++) a += x.charAt(i) == 'W' ? 1 : 0;
        b = a;
        for (int i = y; i < x.length(); i++) {
            a += x.charAt(i) == 'W' ? 1 : 0;
            a -= x.charAt(i - y) == 'W' ? 1 : 0;
            b = Math.min(b, a);
        }
        return b;
    }
}
