class Solution {
    public int punishmentNumber(int n) {
        int w = 0;
        for (int i = 1; i <= n; i++) {
            String s = String.valueOf(i * i);
            if (m(s, 0, i, 0)) w += i * i;
        }
        return w;
    }

    private boolean m(String s, int x, int y, int c) {
        if (x == s.length()) return c == y;
        int t = 0;
        for (int i = x; i < s.length(); i++) {
            t = t * 10 + (s.charAt(i) - '0');
            if (c + t > y) break;
            if (m(s, i + 1, y, c + t)) return true;
        }
        return false;
    }
}
