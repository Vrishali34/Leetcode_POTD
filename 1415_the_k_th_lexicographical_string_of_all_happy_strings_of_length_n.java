class Solution {
    public String getHappyString(int n, int k) {
        int[] u = {0}; 
        String[] p = {""};
        return w(n, k, "", -1, u, p) ? p[0] : "";
    }

    private boolean w(int n, int k, String x, int y, int[] u, String[] p) {
        if (x.length() == n) return ++u[0] == k ? (p[0] = x) != null : false;
        for (int i = 0; i < 3; i++) 
            if (y != i && w(n, k, x + (char) (97 + i), i, u, p)) return true;
        return false;
    }
}
