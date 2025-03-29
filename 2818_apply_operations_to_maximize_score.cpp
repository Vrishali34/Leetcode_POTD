class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        int m = 1e9+7, n = a.size();
        vector<int> f(1e5+2), g(n), l(n, -1), r(n, n);
        iota(f.begin(), f.end(), 0);
        for (int i = 2; i * i < f.size(); ++i)
            for (int j = i*i; j < f.size(); j += i)
                f[j] = min(f[j], i);
        for (int i = 0; i < n; ++i) {
            unordered_set<int> s;
            for (int x = a[i]; x > 1; x /= f[x]) s.insert(f[x]);
            g[i] = s.size();
        }
        stack<int> z;
        for (int i = n-1; i >= 0; --i) {
            while (!z.empty() && g[z.top()] <= g[i]) l[z.top()] = i, z.pop();
            z.push(i);
        }
        z = {};
        for (int i = 0; i < n; ++i) {
            while (!z.empty() && g[z.top()] < g[i]) r[z.top()] = i, z.pop();
            z.push(i);
        }
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j){
            return a[i] > a[j] || (a[i] == a[j] && i < j);
        });
        long res = 1;
        for (int i : idx) {
            long cnt = (long)(i - l[i]) * (r[i] - i);
            cnt = min((long)k, cnt); k -= cnt;
            long p = 1, b = a[i];
            while (cnt) {
                if (cnt & 1) p = p * b % m;
                b = b * b % m;
                cnt >>= 1;
            }
            res = res * p % m;
            if (!k) break;
        }
        return res;
    }
};
