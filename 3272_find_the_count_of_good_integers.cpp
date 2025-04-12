class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        int m = (n + 1) / 2, lo = pow(10, m - 1), hi = pow(10, m);
        unordered_set<string> bag;
        long z = 0;
        for (int i = lo; i < hi; ++i) {
            string s = to_string(i), t = s;
            reverse(t.begin(), t.end());
            s += t.substr(n % 2);
            if (stoll(s) % k) continue;
            string u = s; sort(u.begin(), u.end());
            if (!bag.insert(u).second) continue;
            vector<int> f(10);
            for (char c : s) ++f[c - '0'];
            long p = n - f[0], q = 1;
            for (int j = 2; j < n; ++j) p *= j;
            for (int x : f) for (int j = 2; j <= x; ++j) q *= j;
            z += p / q;
        }
        return z;
    }
};
