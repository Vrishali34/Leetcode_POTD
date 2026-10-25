class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int row_cnt = grid.size(), col_cnt = grid[0].size(), island_cnt = 0;
        int dir_arr[5] = {0, 1, 0, -1, 0};

        auto sinkLand = [&](int start_row, int start_col) {
            vector<pair<int, int>> land_stack{{start_row, start_col}};
            grid[start_row][start_col] = 1;
            bool is_closed = true;
            while (!land_stack.empty()) {
                auto [cur_row, cur_col] = land_stack.back();
                land_stack.pop_back();
                if (!cur_row || !cur_col || cur_row == row_cnt - 1 || cur_col == col_cnt - 1)
                    is_closed = false;
                for (int d = 0; d < 4; d++) {
                    int next_row = cur_row + dir_arr[d], next_col = cur_col + dir_arr[d + 1];
                    if (next_row >= 0 && next_col >= 0 && next_row < row_cnt && next_col < col_cnt && !grid[next_row][next_col]) {
                        grid[next_row][next_col] = 1;
                        land_stack.push_back({next_row, next_col});
                    }
                }
            }
            return is_closed;
        };

        for (int r = 0; r < row_cnt; r++)
            for (int c = 0; c < col_cnt; c++)
                if (!grid[r][c])
                    island_cnt += sinkLand(r, c);

        return island_cnt;
    }
};
