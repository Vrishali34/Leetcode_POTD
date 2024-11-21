class Solution {
public:
    int countUnguarded(int g, int h, vector<vector<int>>& i, vector<vector<int>>& j) {
        vector<vector<int>> k(g, vector<int>(h, 0));
        vector<pair<int, int>> l = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto m : j) k[m[0]][m[1]] = -1;
        for (auto m : i) k[m[0]][m[1]] = 2;
        for (auto m : i) {
            for (auto n : l) {
                int o = m[0], p = m[1];
                while (1) {
                    o += n.first, p += n.second;
                    if (o < 0 || o >= g || p < 0 || p >= h || k[o][p] == -1 || k[o][p] == 2) break;
                    if (k[o][p] == 0) k[o][p] = 1;
                }
            }
        }
        int r = 0;
        for (int a = 0; a < g; a++) for (int b = 0; b < h; b++) if (k[a][b] == 0) r++;
        return r;
    }
};
