class Solution {
public:
    bool blip(vector<int> j[], int k, vector<int>& z, int p) {
        z[k] = p;
        for (int e : j[k]) {
            if (z[e] == p) return false;
            if (z[e] == -1 && !blip(j, e, z, 1 - p)) return false;
        }
        return true;
    }
    int jet(vector<int> g[], int m, int o) {
        vector<bool> a(o, false);
        queue<int> q;
        q.push(m);
        a[m] = true;
        int l = 1;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int v = q.front();
                q.pop();
                for (int w : g[v]) {
                    if (!a[w]) {
                        a[w] = true;
                        q.push(w);
                    }
                }
            }
            l++;
        }
        return l - 1;
    }
    int flip(vector<int> d[], int p, vector<bool>& v, int f, vector<int>& u) {
        int maxn = u[f];
        v[f] = true;
        for (int r : d[f]) {
            if (!v[r]) {
                maxn = max(maxn, flip(d, p, v, r, u));
            }
        }
        return maxn;
    }
    int magnificentSets(int p, vector<vector<int>>& t) {
        vector<int> r[p];
        for (auto& c : t) {
            int i = c[0] - 1, j = c[1] - 1;
            r[i].push_back(j);
            r[j].push_back(i);
        }
        vector<int> c(p, -1), b(p);
        for (int i = 0; i < p; i++) {
            if (c[i] == -1 && !blip(r, i, c, 1)) return -1;
            b[i] = jet(r, i, p);
        }
        vector<bool> k(p, false);
        int m = 0;
        for (int i = 0; i < p; i++) {
            if (!k[i]) m += flip(r, p, k, i, b);
        }
        return m;
    }
};
