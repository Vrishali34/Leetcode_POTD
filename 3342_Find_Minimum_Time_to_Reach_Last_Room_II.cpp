class Solution {
public:
    int minTimeToReach(vector<vector<int>>& m) {
        int n = m.size(), k = m[0].size();
        vector<vector<bool>> vis(n, vector<bool>(k, false));
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<>> pq;
        pq.push({0, 0, 0, 1}); // {time, x, y, parity}
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        
        while (!pq.empty()) {
            auto [tm, x, y, pr] = pq.top(); pq.pop();
            if (x == n - 1 && y == k - 1) return tm;
            if (vis[x][y]) continue;
            vis[x][y] = true;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && ny >= 0 && nx < n && ny < k && !vis[nx][ny]) {
                    int wait = max(tm, m[nx][ny]);
                    pq.push({wait + pr, nx, ny, 3 - pr});
                }
            }
        }
        return -1;
    }
};
