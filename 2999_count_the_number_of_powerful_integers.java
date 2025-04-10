class Solution {
    long[] t = new long[17], p = new long[17];

    void z() {
        if (t[0] == 1) return;
        t[0] = 1;
        for (int i = 1; i < 17; i++) t[i] = t[i - 1] * 10;
    }

    void y(int b) {
        p[0] = 1;
        for (int i = 1; i < 17; i++) p[i] = p[i - 1] * b;
    }

    long x(long u, long v, int d, int m) {
        if (u < v) return 0;
        long u0 = u / t[d], r = u % t[d], z = 0;
        int j = 0;
        while (j < 17 && t[j] <= u0) j++;
        for (int i = j - 1; i >= 0; i--) {
            long q = u0 / t[i];
            if (q > m) return z + p[i + 1];
            z += p[i] * q;
            u0 -= q * t[i];
        }
        return z + (r >= v ? 1 : 0);
    }

    public long numberOfPowerfulInt(long a, long b, int m, String s) {
        z();
        y(m + 1);
        long v = Long.parseLong(s);
        return x(b, v, s.length(), m) - x(a - 1, v, s.length(), m);
    }
}
