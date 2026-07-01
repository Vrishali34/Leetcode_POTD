class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int grid_dim = grid.size();
        if (grid[0][0] == 1 || grid[grid_dim - 1][grid_dim - 1] == 1) return 0;
        vector<vector<int>> zone_dist(grid_dim, vector<int>(grid_dim, -1));
        queue<pair<int, int>> thief_q;
        for (int r_idx = 0; r_idx < grid_dim; ++r_idx) {
            for (int c_idx = 0; c_idx < grid_dim; ++c_idx) {
                if (grid[r_idx][c_idx] == 1) {
                    thief_q.push({r_idx, c_idx});
                    zone_dist[r_idx][c_idx] = 0;
                }
            }
        }
        int shift_x[] = {-1, 1, 0, 0}, shift_y[] = {0, 0, -1, 1};
        while (!thief_q.empty()) {
            auto [curr_r, curr_c] = thief_q.front();
            thief_q.pop();
            for (int i = 0; i < 4; ++i) {
                int next_r = curr_r + shift_x[i], next_c = curr_c + shift_y[i];
                if (next_r >= 0 && next_r < grid_dim && next_c >= 0 && next_c < grid_dim && zone_dist[next_r][next_c] == -1) {
                    zone_dist[next_r][next_c] = zone_dist[curr_r][curr_c] + 1;
                    thief_q.push({next_r, next_c});
                }
            }
        }
        priority_queue<tuple<int, int, int>> path_pq;
        vector<vector<int>> max_safe(grid_dim, vector<int>(grid_dim, -1));
        path_pq.push({zone_dist[0][0], 0, 0});
        max_safe[0][0] = zone_dist[0][0];
        while (!path_pq.empty()) {
            auto [curr_factor, r_pos, c_pos] = path_pq.top();
            path_pq.pop();
            if (r_pos == grid_dim - 1 && c_pos == grid_dim - 1) return curr_factor;
            if (curr_factor < max_safe[r_pos][c_pos]) continue;
            for (int i = 0; i < 4; ++i) {
                int adj_r = r_pos + shift_x[i], adj_c = c_pos + shift_y[i];
                if (adj_r >= 0 && adj_r < grid_dim && adj_c >= 0 && adj_c < grid_dim) {
                    int step_factor = min(curr_factor, zone_dist[adj_r][adj_c]);
                    if (step_factor > max_safe[adj_r][adj_c]) {
                        max_safe[adj_r][adj_c] = step_factor;
                        path_pq.push({step_factor, adj_r, adj_c});
                    }
                }
            }
        }
        return 0;
    }
};
