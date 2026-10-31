class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int rowCnt = grid.size(), colCnt = grid[0].size(), mod = 1e9 + 7;
        vector<vector<int>> landRight(rowCnt + 2, vector<int>(colCnt + 2, -1)), landDown = landRight;
        for (int r = rowCnt - 1; r >= 0; r--)
            for (int c = colCnt - 1; c >= 0; c--) {
                int cellId = r * colCnt + c;
                landRight[r][c] = grid[r][c] ? landDown[r + 1][c] : cellId;
                landDown[r][c] = grid[r][c] ? landRight[r][c + 1] : cellId;
            }

        vector<vector<int>> ways(rowCnt, vector<int>(colCnt));
        ways[0][0] = 1;
        for (int r = 0; r < rowCnt; r++)
            for (int c = 0; c < colCnt; c++) {
                if (!ways[r][c]) continue;
                for (int target : {landRight[r][c + 1], landDown[r + 1][c]})
                    if (target >= 0) {
                        int& cur = ways[target / colCnt][target % colCnt];
                        cur = (cur + ways[r][c]) % mod;
                    }
            }
        return ways[rowCnt - 1][colCnt - 1];
    }
};
