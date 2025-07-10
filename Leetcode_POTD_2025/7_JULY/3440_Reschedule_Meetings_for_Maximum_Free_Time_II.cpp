class Solution {
public:
    int maxFreeTime(int z, vector<int>& a, vector<int>& b) {
        int n = a.size(), p = 0, q = a[0], mx = 0;
        vector<int> h;
        for (int i = 1; i < n; ++i) h.push_back(a[i] - b[i - 1]);
        h.insert(h.begin(), q), h.push_back(z - b[n - 1]);

        vector<int> suf(h.size()); suf.back() = 0;
        for (int i = h.size() - 2; i >= 0; --i) suf[i] = max(suf[i + 1], h[i + 1]);

        for (int i = 1; i < h.size(); ++i) {
            int dur = b[i - 1] - a[i - 1];
            if (dur <= max(p, suf[i])) mx = max(mx, h[i - 1] + h[i] + dur);
            mx = max(mx, h[i - 1] + h[i]);
            p = max(p, h[i - 1]);
        }
        return mx;
    }
};
