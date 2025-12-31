class Solution {
public:
    int latestDayToCross(int r_cnt, int c_cnt, vector<vector<int>>& flood_list) {
        int low_day = 1, high_day = r_cnt * c_cnt, final_day = 0;
        while (low_day <= high_day) {
            int mid_day = low_day + (high_day - low_day) / 2;
            if (can_pass(r_cnt, c_cnt, mid_day, flood_list)) {
                final_day = mid_day;
                low_day = mid_day + 1;
            } else high_day = mid_day - 1;
        }
        return final_day;
    }

    bool can_pass(int rows, int cols, int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(rows, vector<int>(cols, 0));
        for (int i = 0; i < day; ++i) grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        queue<pair<int, int>> q_path;
        for (int c = 0; c < cols; ++c) {
            if (!grid[0][c]) {
                q_path.push({0, c});
                grid[0][c] = 1;
            }
        }
        int dr[] = {0, 0, 1, -1}, dc[] = {1, -1, 0, 0};
        while (!q_path.empty()) {
            auto [curr_r, curr_c] = q_path.front(); q_path.pop();
            if (curr_r == rows - 1) return true;
            for (int i = 0; i < 4; ++i) {
                int nr = curr_r + dr[i], nc = curr_c + dc[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !grid[nr][nc]) {
                    grid[nr][nc] = 1;
                    q_path.push({nr, nc});
                }
            }
        }
        return false;
    }
};
