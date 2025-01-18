class Solution {  
public:  
    int minCost(vector<vector<int>>& g) {  
        int m = g.size(), n = g[0].size();  
        deque<pair<int, int>> q;  
        vector<vector<int>> d(m, vector<int>(n, INT_MAX));  
        q.push_front({0, 0});  
        d[0][0] = 0;  
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  
        while (!q.empty()) {  
            auto [x, y] = q.front();  
            q.pop_front();  
            for (int i = 0; i < 4; i++) {  
                int nx = x + dirs[i][0], ny = y + dirs[i][1], nc = d[x][y] + (g[x][y] != i + 1);  
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && nc < d[nx][ny]) {  
                    d[nx][ny] = nc;  
                    if (g[x][y] == i + 1) q.push_front({nx, ny});  
                    else q.push_back({nx, ny});  
                }  
            }  
        }  
        return d[m - 1][n - 1];  
    }  
};  
