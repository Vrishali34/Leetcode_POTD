class Solution {
public:
    int maxTaskAssign(vector<int>& a, vector<int>& b, int p, int s) {
        sort(a.begin(), a.end()), sort(b.begin(), b.end());
        int l = 0, h = min(a.size(), b.size()), r = 0;
        while (l <= h) {
            int m = (l + h) / 2, x = p;
            multiset<int> z(b.end() - m, b.end());
            bool f = 1;
            for (int i = m - 1; i >= 0; --i) {
                auto it = prev(z.end());
                if (*it >= a[i]) z.erase(it);
                else if (x) {
                    it = z.lower_bound(a[i] - s);
                    if (it == z.end()) { f = 0; break; }
                    z.erase(it); --x;
                } else { f = 0; break; }
            }
            f ? r = m, l = m + 1 : h = m - 1;
        }
        return r;
    }
};
