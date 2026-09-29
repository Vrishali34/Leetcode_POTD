class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int row_cnt = grid.size(), col_cnt = grid[0].size();
        int path_len = row_cnt + col_cnt - 1;
        if (path_len % 2 == 1 || grid[0][0] != '(' || grid[row_cnt-1][col_cnt-1] != ')')
            return false;

        vector<vector<vector<int>>> visit_state(row_cnt, vector<vector<int>>(col_cnt, vector<int>(row_cnt + col_cnt, 0)));
        return dfs_walk(grid, 0, 0, 0, row_cnt, col_cnt, visit_state);
    }

private:
    bool dfs_walk(vector<vector<char>>& grid, int cur_row, int cur_col, int open_bal, int row_cnt, int col_cnt, vector<vector<vector<int>>>& visit_state) {
        open_bal += (grid[cur_row][cur_col] == '(') ? 1 : -1;
        int steps_left = (row_cnt - 1 - cur_row) + (col_cnt - 1 - cur_col);
        if (open_bal < 0 || open_bal > steps_left) return false;
        if (cur_row == row_cnt - 1 && cur_col == col_cnt - 1) return open_bal == 0;

        if (visit_state[cur_row][cur_col][open_bal] != 0)
            return visit_state[cur_row][cur_col][open_bal] == 1;

        bool found_path = false;
        if (cur_row + 1 < row_cnt)
            found_path = dfs_walk(grid, cur_row + 1, cur_col, open_bal, row_cnt, col_cnt, visit_state);
        if (!found_path && cur_col + 1 < col_cnt)
            found_path = dfs_walk(grid, cur_row, cur_col + 1, open_bal, row_cnt, col_cnt, visit_state);

        visit_state[cur_row][cur_col][open_bal] = found_path ? 1 : 2;
        return found_path;
    }
};
