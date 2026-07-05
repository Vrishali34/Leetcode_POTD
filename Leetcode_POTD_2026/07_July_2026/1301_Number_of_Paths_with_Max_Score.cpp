class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int gridSize = board.size();
        int modVal = 1e9 + 7;
        vector<vector<int>> maxScore(gridSize, vector<int>(gridSize, -1));
        vector<vector<int>> pathCount(gridSize, vector<int>(gridSize, 0));
        maxScore[gridSize - 1][gridSize - 1] = 0;
        pathCount[gridSize - 1][gridSize - 1] = 1;
        for (int r = gridSize - 1; r >= 0; --r) {
            for (int c = gridSize - 1; c >= 0; --c) {
                if (board[r][c] == 'X' || maxScore[r][c] == -1) continue;
                int currScore = maxScore[r][c];
                int currWays = pathCount[r][c];
                int dr[] = {-1, 0, -1};
                int dc[] = {0, -1, -1};
                for (int i = 0; i < 3; ++i) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr >= 0 && nc >= 0 && board[nr][nc] != 'X') {
                        int weight = (board[nr][nc] == 'E') ? 0 : (board[nr][nc] - '0');
                        int nextScore = currScore + weight;
                        if (nextScore > maxScore[nr][nc]) {
                            maxScore[nr][nc] = nextScore;
                            pathCount[nr][nc] = currWays;
                        } else if (nextScore == maxScore[nr][nc]) {
                            pathCount[nr][nc] = (pathCount[nr][nc] + currWays) % modVal;
                        }
                    }
                }
            }
        }
        return maxScore[0][0] == -1 ? vector<int>{0, 0} : vector<int>{maxScore[0][0], pathCount[0][0]};
    }
};
