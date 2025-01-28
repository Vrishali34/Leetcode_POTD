class Solution {
public:
    int findMaxFish(vector<vector<int>>& a) {
        int p = 0, v = a.size(), h = a[0].size();
        for (int u = 0; u < v; ++u)
            for (int o = 0; o < h; ++o)
                if (a[u][o]) {
                    int e = 0;
                    queue<pair<int, int>> z;
                    z.push({u, o});
                    while (!z.empty()) {
                        auto [f, g] = z.front();
                        z.pop();
                        if (a[f][g]) {
                            e += a[f][g];
                            a[f][g] = 0;
                            if (f && a[f - 1][g]) z.push({f - 1, g});
                            if (f + 1 < v && a[f + 1][g]) z.push({f + 1, g});
                            if (g && a[f][g - 1]) z.push({f, g - 1});
                            if (g + 1 < h && a[f][g + 1]) z.push({f, g + 1});
                        }
                    }
                    p = max(p, e);
                }
        return p;
    }
};
