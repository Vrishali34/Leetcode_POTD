class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mT) {
        int r = mT.size(), c = mT[0].size();
        vector<vector<int>> t(r, vector<int>(c, INT_MAX));
        int dX[] = {-1, 1, 0, 0}, dY[] = {0, 0, -1, 1};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> q;
        t[0][0] = 0;
        q.push({0, 0, 0});
        
        while (!q.empty()) {
            auto [x, y, time] = q.top(); q.pop();
            if (x == r - 1 && y == c - 1) return time;
            if (t[x][y] < time) continue;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dX[i], ny = y + dY[i];
                if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
                    int arrTime = time + 1;
                    int delay = max(0, mT[nx][ny] - t[x][y]);
                    arrTime += delay;
                    if (arrTime < t[nx][ny]) {
                        t[nx][ny] = arrTime;
                        q.push({nx, ny, arrTime});
                    }
                }
            }
        }
        return -1;
    }
};
