class Solution {
    public int maxScore(String a) {
        int b = a.length(), c = 0, d = a.charAt(0) == '0' ? 1 : 0, e = d;
        for (int f = 1; f < b - 1; f++) {
            if (a.charAt(f) == '0') {
                d++;
            } else {
                c++;
                d--;
            }
            e = Math.max(e, d);
        }
        c += (a.charAt(b - 1) == '1' ? 1 : 0);
        return c + e;
    }
}
