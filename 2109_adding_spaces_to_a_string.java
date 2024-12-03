class Solution {
    public String addSpaces(String s, int[] idx) {
        StringBuilder out = new StringBuilder(s.length() + idx.length);
        int m = 0, n = 0;
        for (int o = 0; o < s.length(); o++) {
            if (n < idx.length && o == idx[n]) {
                out.append(' ');
                n++;
            }
            out.append(s.charAt(o));
        }
        return out.toString();
    }
}
