class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<bool> vis(n, false), inPath(n, false), safe(n, false);
        for (int i = 0; i < n; ++i) dfs(i, g, vis, inPath, safe);
        vector<int> res;
        for (int i = 0; i < n; ++i) if (safe[i]) res.push_back(i);
        return res;
    }

private:
    bool dfs(int node, vector<vector<int>>& g, vector<bool>& vis, vector<bool>& inPath, vector<bool>& safe) {
        if (vis[node]) return safe[node];
        vis[node] = inPath[node] = true;
        for (int neighbor : g[node]) {
            if (inPath[neighbor] || !dfs(neighbor, g, vis, inPath, safe)) return safe[node] = false;
        }
        inPath[node] = false;
        return safe[node] = true;
    }
};
