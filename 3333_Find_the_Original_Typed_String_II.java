class Solution {
    public int possibleStringCount(String txt, int lim) {
        List<Integer> x = new ArrayList<>();
        long m = 1_000_000_007, p = 1;
        for (int a = 0; a < txt.length();) {
            int b = a;
            while (++a < txt.length() && txt.charAt(a) == txt.charAt(b));
            if (a > b + 1) x.add(a - b - 1); 
            if (a > b) p = p * (a - b) % m;
            lim--;
        }
        if (lim <= 0) return (int)p;
        long[] q = new long[lim]; q[0] = 1;
        for (int u : x) {
            for (int i = 1; i < lim; i++) q[i] = (q[i] + q[i - 1]) % m;
            for (int i = lim - 1; i > u; i--) q[i] = (q[i] - q[i - u - 1] + m) % m;
        }
        for (int i = 1; i < lim; i++) q[i] = (q[i] + q[i - 1]) % m;
        return (int)((p - q[lim - 1] + m) % m);
    }
}
