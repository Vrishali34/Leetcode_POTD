class Solution {
public:
    int countCompleteComponents(int w, vector<vector<int>>& x) {
        vector<vector<int>> y(w); for (auto& z : x) y[z[0]].push_back(z[1]), y[z[1]].push_back(z[0]);
        vector<int> u(w), a; int c = 0;
        function<void(int)> dfs = [&](int i) {
            u[i] = 1; a.push_back(i);
            for (int j : y[i]) if (!u[j]) dfs(j);
        };
        for (int i = 0; i < w; ++i) {
            if (!u[i]) {
                a.clear(); dfs(i);
                int e = 0;
                for (int j : a) e += y[j].size();
                if (e / 2 == a.size() * (a.size() - 1) / 2) ++c;
            }
        }
        return c;
    }
};
