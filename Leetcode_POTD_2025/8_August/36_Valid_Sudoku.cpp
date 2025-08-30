class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool tracker[3][9][9] = {false};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int val = board[i][j] - '1';
                int box_idx = (i / 3) * 3 + j / 3;
                if (tracker[0][i][val] || tracker[1][j][val] || tracker[2][box_idx][val]) {
                    return false;
                }
                tracker[0][i][val] = true;
                tracker[1][j][val] = true;
                tracker[2][box_idx][val] = true;
            }
        }
        return true;
    }
};
