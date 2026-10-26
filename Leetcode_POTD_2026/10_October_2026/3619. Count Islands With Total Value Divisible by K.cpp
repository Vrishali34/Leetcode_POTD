class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rowCnt = grid.size(), colCnt = grid[0].size(), islandCnt = 0;
        int dirs[5] = {0, 1, 0, -1, 0};
        for (int r = 0; r < rowCnt; r++) {
            for (int c = 0; c < colCnt; c++) {
                if (!grid[r][c]) continue;
                long long islandSum = grid[r][c];
                grid[r][c] = 0;
                vector<pair<int, int>> cellStack = {{r, c}};
                while (!cellStack.empty()) {
                    auto [curRow, curCol] = cellStack.back();
                    cellStack.pop_back();
                    for (int d = 0; d < 4; d++) {
                        int nextRow = curRow + dirs[d], nextCol = curCol + dirs[d + 1];
                        if (nextRow < 0 || nextCol < 0 || nextRow >= rowCnt || nextCol >= colCnt || !grid[nextRow][nextCol]) continue;
                        islandSum += grid[nextRow][nextCol];
                        grid[nextRow][nextCol] = 0;
                        cellStack.push_back({nextRow, nextCol});
                    }
                }
                if (islandSum % k == 0) islandCnt++;
            }
        }
        return islandCnt;
    }
};
