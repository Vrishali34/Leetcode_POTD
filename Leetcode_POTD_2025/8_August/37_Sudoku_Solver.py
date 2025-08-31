class Solution(object):
    def solveSudoku(self, brd):
        r_fil = [[False] * 9 for _ in range(9)]
        c_fil = [[False] * 9 for _ in range(9)]
        b_fil = [[False] * 9 for _ in range(9)]
        for y in range(9):
            for x in range(9):
                if brd[y][x] != '.':
                    v = int(brd[y][x]) - 1
                    r_fil[y][v] = True
                    c_fil[x][v] = True
                    b_fil[(y // 3) * 3 + x // 3][v] = True
        self.weave_the_tapestry(brd, r_fil, c_fil, b_fil, 0, 0)
    def weave_the_tapestry(self, brd, r_fil, c_fil, b_fil, y, x):
        if y == 9:
            return True
        next_y, next_x = y + (x + 1) // 9, (x + 1) % 9
        if brd[y][x] != '.':
            return self.weave_the_tapestry(brd, r_fil, c_fil, b_fil, next_y, next_x)
        for d in range(9):
            bx_idx = (y // 3) * 3 + x // 3
            if not r_fil[y][d] and not c_fil[x][d] and not b_fil[bx_idx][d]:
                r_fil[y][d] = True
                c_fil[x][d] = True
                b_fil[bx_idx][d] = True
                brd[y][x] = str(d + 1)
                if self.weave_the_tapestry(brd, r_fil, c_fil, b_fil, next_y, next_x):
                    return True
                r_fil[y][d] = False
                c_fil[x][d] = False
                b_fil[bx_idx][d] = False
                brd[y][x] = '.'
        return False
