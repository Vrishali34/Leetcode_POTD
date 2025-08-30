class Solution(object):
    def isValidSudoku(self, board):
        seen = set()
        for i in range(9):
            for j in range(9):
                current_val = board[i][j]
                if current_val != '.':
                    row_key = f"{current_val}in_row{i}"
                    col_key = f"{current_val}in_col{j}"
                    box_key = f"{current_val}in_box{i // 3}-{j // 3}"
                    if row_key in seen or col_key in seen or box_key in seen:
                        return False
                    seen.add(row_key)
                    seen.add(col_key)
                    seen.add(box_key)
        return True
