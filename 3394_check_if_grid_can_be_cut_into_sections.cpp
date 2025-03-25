class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& r) {
        auto z = [&](vector<pair<int,int>> v) {
            sort(v.begin(), v.end());
            int c = 1, m = v[0].second;
            for (auto [a, b] : v) if (a >= m) m = b, ++c; else m = max(m, b);
            return c >= 3;
        };
        vector<pair<int,int>> x, y;
        for (auto& q : r) x.emplace_back(q[0], q[2]), y.emplace_back(q[1], q[3]);
        return z(x) || z(y);
    }
};
