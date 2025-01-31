class Solution {
public:
    int largestIsland(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), q = 2, b = 0;
        unordered_map<int, int> mp;
        vector<int> v{0, 1, 0, -1, 0};
        function<int(int, int, int)> g = [&](int x, int y, int k) {
            if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] != 1) return 0;
            a[x][y] = k;
            return 1 + g(x+1, y, k) + g(x-1, y, k) + g(x, y+1, k) + g(x, y-1, k);
        };
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == 1) mp[q] = g(i, j, q), b = max(b, mp[q++]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!a[i][j]) {
                    unordered_set<int> t;
                    int u = 1;
                    for (int k = 0; k < 4; k++) {
                        int x = i + v[k], y = j + v[k+1];
                        if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] > 1)
                            t.insert(a[x][y]);
                    }
                    for (int x : t) u += mp[x];
                    b = max(b, u);
                }
        return b;
    }
};
