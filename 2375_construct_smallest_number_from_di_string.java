class Solution {
    public String smallestNumber(String m) {
        StringBuilder z = new StringBuilder();
        int x = m.length(), q[] = new int[x];
        q[x - 1] = (m.charAt(x - 1) == 'D') ? 1 : 0;
        for (int i = x - 2; i >= 0; --i) if (m.charAt(i) == 'D') q[i] = q[i + 1] + 1;
        int y = 1;
        for (int i = 0; i < x; ++i) {
            int w = q[i] + y;
            if (w == y) y = i + 2;
            z.append(w);
        }
        return z.append(y).toString();
    }
}
