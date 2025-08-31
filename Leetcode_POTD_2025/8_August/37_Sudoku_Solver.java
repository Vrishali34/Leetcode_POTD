class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows_sieve(9, vector<bool>(9, false));
        vector<vector<bool>> cols_sieve(9, vector<bool>(9, false));
        vector<vector<bool>> boxes_sieve(9, vector<bool>(9, false));
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    int val = board[r][c] - '1';
                    rows_sieve[r][val] = true;
                    cols_sieve[c][val] = true;
                    boxes_sieve[r / 3 * 3 + c / 3][val] = true;
                }
            }
        }
        fill_the_cosmos(board, rows_sieve, cols_sieve, boxes_sieve, 0, 0);
    }
private:
    bool fill_the_cosmos(vector<vector<char>>& puzz_, vector<vector<bool>>& rows_sieve, vector<vector<bool>>& cols_sieve, vector<vector<bool>>& boxes_sieve, int r, int c) {
        if (r == 9) return true;
        int next_r = r + (c + 1) / 9;
        int next_c = (c + 1) % 9;
        if (puzz_[r][c] != '.') {
            return fill_the_cosmos(puzz_, rows_sieve, cols_sieve, boxes_sieve, next_r, next_c);
        }
        for (int dig_ = 0; dig_ < 9; ++dig_) {
            int box_idx = r / 3 * 3 + c / 3;
            if (!rows_sieve[r][dig_] && !cols_sieve[c][dig_] && !boxes_sieve[box_idx][dig_]) {
                rows_sieve[r][dig_] = true;
                cols_sieve[c][dig_] = true;
                boxes_sieve[box_idx][dig_] = true;
                puzz_[r][c] = dig_ + '1';
                if (fill_the_cosmos(puzz_, rows_sieve, cols_sieve, boxes_sieve, next_r, next_c)) {
                    return true;
                }
                rows_sieve[r][dig_] = false;
                cols_sieve[c][dig_] = false;
                boxes_sieve[box_idx][dig_] = false;
                puzz_[r][c] = '.';
            }
        }
        return false;
    }
};
