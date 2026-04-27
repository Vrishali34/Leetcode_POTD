class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int row_limit = grid.size(), col_limit = grid[0].size();
        vector<vector<int>> pipe_map = {{}, {0, 1}, {2, 3}, {0, 3}, {1, 3}, {0, 2}, {1, 2}};
        int dr[] = {0, 0, -1, 1}, dc[] = {-1, 1, 0, 0}, inv[] = {1, 0, 3, 2};
        queue<pair<int, int>> flow_q;
        vector<vector<bool>> seen(row_limit, vector<bool>(col_limit));
        flow_q.push({0, 0});
        seen[0][0] = true;
        while (!flow_q.empty()) {
            auto [r_cur, c_cur] = flow_q.front(); flow_q.pop();
            if (r_cur == row_limit - 1 && c_cur == col_limit - 1) return true;
            for (int d_idx : pipe_map[grid[r_cur][c_cur]]) {
                int nr = r_cur + dr[d_idx], nc = c_cur + dc[d_idx];
                if (nr >= 0 && nr < row_limit && nc >= 0 && nc < col_limit && !seen[nr][nc]) {
                    for (int back_idx : pipe_map[grid[nr][nc]]) {
                        if (back_idx == inv[d_idx]) {
                            seen[nr][nc] = true;
                            flow_q.push({nr, nc});
                        }
                    }
                }
            }
        }
        return false;
    }
};
