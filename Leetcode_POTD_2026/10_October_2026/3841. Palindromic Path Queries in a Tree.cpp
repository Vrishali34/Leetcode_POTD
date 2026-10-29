class Solution {
public:
vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
    vector<vector<int>> nbr(n);
    for (auto& e : edges) nbr[e[0]].push_back(e[1]), nbr[e[1]].push_back(e[0]);
    vector<int> par(n, -1), dep(n), sz(n, 1), heavyKid(n, -1), chainTop(n), slot(n), order{0};
    for (int i = 0; i < (int)order.size(); i++) {
        int u = order[i];
        for (int v : nbr[u]) if (v != par[u]) par[v] = u, dep[v] = dep[u] + 1, order.push_back(v);
    }
    for (int i = n - 1; i > 0; i--) {
        int u = order[i], p = par[u];
        sz[p] += sz[u];
        if (heavyKid[p] < 0 || sz[u] > sz[heavyKid[p]]) heavyKid[p] = u;
    }
    int cnt = 1;
    for (int u : order)
        if (u == 0 || heavyKid[par[u]] != u)
            for (int v = u; v >= 0; v = heavyKid[v]) chainTop[v] = u, slot[v] = cnt++;
    vector<int> bit(n + 1);
    auto flip = [&](int i, int m) { for (; i <= n; i += i & -i) bit[i] ^= m; };
    auto pref = [&](int i) { int r = 0; for (; i; i -= i & -i) r ^= bit[i]; return r; };
    for (int i = 0; i < n; i++) flip(slot[i], 1 << (s[i] - 'a'));
    vector<bool> ans;
    for (auto& q : queries) {
        istringstream ss(q);
        string op;
        int a;
        ss >> op >> a;
        if (op[0] == 'u') {
            char ch;
            ss >> ch;
            flip(slot[a], (1 << (s[a] - 'a')) ^ (1 << (ch - 'a')));
            s[a] = ch;
        } else {
            int b, mask = 0;
            ss >> b;
            while (chainTop[a] != chainTop[b]) {
                if (dep[chainTop[a]] < dep[chainTop[b]]) swap(a, b);
                mask ^= pref(slot[a]) ^ pref(slot[chainTop[a]] - 1);
                a = par[chainTop[a]];
            }
            if (dep[a] > dep[b]) swap(a, b);
            mask ^= pref(slot[b]) ^ pref(slot[a] - 1);
            ans.push_back(!(mask & (mask - 1)));
        }
    }
    return ans;
}
};
