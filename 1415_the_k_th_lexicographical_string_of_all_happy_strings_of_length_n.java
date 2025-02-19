class Solution {
    public String getHappyString(int n, int k) {
        int[] u = {0}; String[] p = {""};
        boolean w(String x, int y) {
            if (x.length() == n) return ++u[0] == k ? (p[0] = x) != null : false;
            for (int i = 0; i < 3; i++) if (y != i && w(x + (char) (97 + i), i)) return true;
            return false;
        }
        return w("", -1) ? p[0] : "";
    }
}
