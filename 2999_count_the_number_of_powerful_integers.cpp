long long u[17], v[17];
class Solution {
public:
    void r() { u[0] = 1; for (int i = 1; i < 17; i++) u[i] = u[i - 1] * 10; }
    void s(int a) { v[0] = 1; for (int i = 1; i < 17; i++) v[i] = v[i - 1] * a; }
    long long t(long long x, long long y, int z, int k) {
        if (x < y) return 0;
        long long p = x / u[z], q = x % u[z], ans = 0;
        int i = lower_bound(u, u + 17, p) - u;
        while (i >= 0) {
            auto [a, b] = ldiv(p, u[i]);
            if (a > k) return ans + v[i + 1];
            ans += v[i] * a;
            p -= a * u[i--];
        }
        return ans + (q >= y);
    }
    long long numberOfPowerfulInt(long long a, long long b, int c, string& d) {
        r(); s(c + 1);
        return t(b, stoll(d), d.size(), c) - t(a - 1, stoll(d), d.size(), c);
    }
};
