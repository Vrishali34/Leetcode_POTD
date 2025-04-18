class Solution {
    public String countAndSay(int n) {
        String a = "1";
        while (--n > 0) {
            StringBuilder b = new StringBuilder();
            for (int u = 0, v; u < a.length(); u = v) {
                v = u + 1;
                while (v < a.length() && a.charAt(u) == a.charAt(v)) v++;
                b.append(v - u).append(a.charAt(u));
            }
            a = b.toString();
        }
        return a;
    }
}
