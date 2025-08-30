class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<String> seen = new HashSet<>();
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                char current_val = board[row][col];
                if (current_val != '.') {
                    if (!seen.add(current_val + "in_row" + row) ||
                        !seen.add(current_val + "in_col" + col) ||
                        !seen.add(current_val + "in_box" + row / 3 + "-" + col / 3)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
