class Solution {
    public boolean canBeValid(String a, String b) {
        int c = a.length(), d = 0;
        if ((c & 1) == 1) return false;
        for (int e = 0; e < c; e++) {
            d += (a.charAt(e) == '(' || b.charAt(e) == '0') ? 1 : -1;
            if (d < 0) return false;
        }
        d = 0;
        for (int e = c - 1; e >= 0; e--) {
            d += (a.charAt(e) == ')' || b.charAt(e) == '0') ? 1 : -1;
            if (d < 0) return false;
        }
        return true;
    }
}
