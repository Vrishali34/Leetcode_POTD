class Solution {
public:
    int minimumObstacles(vector<vector<int>>& p) {
        int h = p.size(), w = p[0].size();
        deque<pair<int, int>> d;
        vector<vector<int>> f(h, vector<int>(w, INT_MAX));
        d.push_front({0, 0}), f[0][0] = 0;
        while (!d.empty()) {
            auto [a, b] = d.front();
            d.pop_front();
            for (auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
                int nx = a + dx, ny = b + dy;
                if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                    int nw = f[a][b] + p[nx][ny];
                    if (nw < f[nx][ny]) {
                        f[nx][ny] = nw;
                        if (p[nx][ny]) d.push_back({nx, ny});
                        else d.push_front({nx, ny});
                    }
                }
            }
        }
        return f[h - 1][w - 1];
    }
};
