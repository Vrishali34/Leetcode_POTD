class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edg, vector<int>& val, int k) {
        vector<vector<int>> g(n);
        vector<int> deg(n);
        if (n < 2) return 1;
        for (auto& e : edg) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }
        vector<long long> v(val.begin(), val.end());
        queue<int> q;
        for (int i = 0; i < n; i++) if (deg[i] == 1) q.push(i);
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            deg[u]--;
            long long rem = 0;
            if (v[u] % k == 0) cnt++;
            else rem = v[u];
            for (int nbh : g[u]) {
                if (deg[nbh] == 0) continue;
                deg[nbh]--;
                v[nbh] += rem;
                if (deg[nbh] == 1) q.push(nbh);
            }
        }
        return cnt;
    }
};
