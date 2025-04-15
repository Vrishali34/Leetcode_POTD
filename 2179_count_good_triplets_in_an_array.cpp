class Solution {
public:
    long long goodTriplets(vector<int>& x, vector<int>& y) {
        int n = x.size(); vector<int> m(n), l(n), r(n); for (int i = 0; i < n; i++) m[x[i]] = i;
        vector<int> z(n); for (int i = 0; i < n; i++) z[i] = m[y[i]];
        vector<int> f(n + 2); auto u = [&](int i) { while (i <= n) f[i]++, i += i & -i; };
        auto g = [&](int i) { int s = 0; while (i) s += f[i], i -= i & -i; return s; };
        for (int i = 0; i < n; i++) l[i] = g(z[i]), u(z[i] + 1);
        fill(f.begin(), f.end(), 0);
        for (int i = n - 1; ~i; i--) r[i] = g(n) - g(z[i] + 1), u(z[i] + 1);
        long long t = 0; for (int i = 0; i < n; i++) t += 1LL * l[i] * r[i];
        return t;
    }
};
