class Solution {
public:
    vector<bool> checkIfPrerequisite(int z, vector<vector<int>>& x, vector<vector<int>>& y) {
        unordered_map<int, unordered_set<int>> w;
        for (auto& v : x) w[v[1]].insert(v[0]);
        for (int a = 0; a < z; ++a)
            for (int b = 0; b < z; ++b)
                if (w[b].count(a)) w[b].insert(w[a].begin(), w[a].end());
        vector<bool> r;
        for (auto& u : y) r.push_back(w[u[1]].count(u[0]) > 0);
        return r;
    }
};
