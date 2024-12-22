class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& a, vector<vector<int>>& q) {
        vector<int> r(q.size(), -1);
        vector<pair<int, int>> p, b;
        int n = a.size();
        for (int i = 0; i < q.size(); i++) {
            int x = min(q[i][0], q[i][1]);
            int y = max(q[i][0], q[i][1]);
            if (x == y || a[x] < a[y]) r[i] = y;
            else b.push_back({y, i});
        }
        sort(b.begin(), b.end(), greater<>());
        int j = n - 1;
        for (auto t : b) {
            int x = min(q[t.second][0], q[t.second][1]);
            int y = max(q[t.second][0], q[t.second][1]);
            for (; j > y; j--) {
                while (!p.empty() && a[p.back().second] < a[j]) p.pop_back();
                p.push_back({a[j], j});
            }
            auto it = upper_bound(p.rbegin(), p.rend(), make_pair(a[x], n));
            r[t.second] = (it == p.rend()) ? -1 : it->second;
        }
        return r;
    }
};
