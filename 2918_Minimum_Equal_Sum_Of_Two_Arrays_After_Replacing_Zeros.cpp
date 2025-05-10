class Solution {
public:
    long long minSum(vector<int>& x, vector<int>& y) {
        auto s = [](auto& v) { return accumulate(v.begin(), v.end(), 0LL); };
        auto z = [](auto& v) { return count(v.begin(), v.end(), 0); };
        long long a = s(x), b = s(y); int p = z(x), q = z(y);
        return (!p && a < b + q) || (!q && b < a + p) ? -1 : max(a + p, b + q);
    }
};
