class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rowNum = grid.size(), colNum = grid[0].size(), commServers = 0;
        vector<int> rowCnt(rowNum), colCnt(colNum);
        for (int r = 0; r < rowNum; r++)
            for (int c = 0; c < colNum; c++)
                if (grid[r][c]) rowCnt[r]++, colCnt[c]++;
        for (int r = 0; r < rowNum; r++)
            for (int c = 0; c < colNum; c++)
                if (grid[r][c] && (rowCnt[r] > 1 || colCnt[c] > 1)) commServers++;
        return commServers;
    }
};
