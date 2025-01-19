class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> z;
        vector<vector<bool>> v(h.size(), vector<bool>(h[0].size(), 0));
        for (int i = 0; i < h.size(); i++) 
            for (int j = 0; j < h[0].size(); j++) 
                if (i == 0 || i == h.size() - 1 || j == 0 || j == h[0].size() - 1) 
                    z.push({h[i][j], {i, j}}), v[i][j] = 1;
        int x = 0, d[] = {-1, 0, 1, 0};
        while (!z.empty()) {
            auto f = z.top(); z.pop();
            for (int k = 0; k < 4; k++) {
                int a = f.second.first + d[k], b = f.second.second + d[k ^ 1];
                if (a >= 0 && a < h.size() && b >= 0 && b < h[0].size() && !v[a][b]) {
                    x += max(0, f.first - h[a][b]);
                    z.push({max(h[a][b], f.first), {a, b}});
                    v[a][b] = 1;
                }
            }
        }
        return x;
    }
};
