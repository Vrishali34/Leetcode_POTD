class Solution {
    public int minChanges(String s) {
        int c = 0;
        for (int i = 0; i < s.length(); i += 2) {
            c += (s.charAt(i) != s.charAt(i + 1)) ? 1 : 0;
        }
        return c;
    }
}
