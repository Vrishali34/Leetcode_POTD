class Solution {
public:
    int colorTheGrid(int a, int b) {
        int M = 1e9+7;
        vector<vector<int>> x;
        for (int i = 0; i < pow(3,a); ++i) {
            vector<int> s(a);
            int u = i;
            for (int j = 0; j < a; ++j, u /= 3) s[j] = u % 3;
            bool ok = 1;
            for (int j = 1; j < a; ++j) if (s[j] == s[j-1]) ok = 0;
            if (ok) x.push_back(s);
        }
        int n = x.size();
        vector<vector<int>> z(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                bool ok = 1;
                for (int k = 0; k < a; ++k) if (x[i][k] == x[j][k]) ok = 0;
                if (ok) z[i].push_back(j);
            }
        vector<int> d(n,1);
        for (int i = 1; i < b; ++i) {
            vector<int> nd(n);
            for (int j = 0; j < n; ++j)
                for (int k : z[j]) nd[k] = (nd[k] + d[j]) % M;
            d = nd;
        }
        int res = 0;
        for (int u : d) res = (res + u) % M;
        return res;
    }
};
