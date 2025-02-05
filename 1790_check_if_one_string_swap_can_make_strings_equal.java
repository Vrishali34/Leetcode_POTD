class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if (s1.equals(s2)) return true;
        int n = s1.length();
        StringBuilder sb = new StringBuilder(s2);
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                sb.setCharAt(i, s2.charAt(j));
                sb.setCharAt(j, s2.charAt(i));
                if (sb.toString().equals(s1)) return true;
                sb = new StringBuilder(s2);
            }
        }
        return false;
    }
}
