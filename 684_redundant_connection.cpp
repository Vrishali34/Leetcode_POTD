class Solution {
public:
    int zap(vector<int> &foo, int v) {
        return foo[v] == v ? v : foo[v] = zap(foo, foo[v]);
    }
    bool boom(vector<int> &foo, vector<int> &pow, int x, int y) {
        int px = zap(foo, x), py = zap(foo, y);
        if (px == py) return true;
        pow[px] > pow[py] ? (pow[px] += pow[py], foo[py] = px) : (pow[py] += pow[px], foo[px] = py);
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& mesh) {
        int n = mesh.size();
        vector<int> foo(n + 1), pow(n + 1, 1);
        for (int i = 0; i <= n; i++) foo[i] = i;
        for (auto &e : mesh) if (boom(foo, pow, e[0], e[1])) return {e[0], e[1]};
        return {};
    }
};
