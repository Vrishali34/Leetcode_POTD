class Solution(object):
    def lenOfVDiagonal(self, grid):
        dx, dy = [-1, -1, 1, 1], [-1, 1, 1, -1]

        def inside(x, y, R, C):
            return 0 <= x < R and 0 <= y < C

        def good(v, s):
            return (s == 0 and v == 1) or (s % 2 == 1 and v == 2) or (s % 2 == 0 and s > 0 and v == 0)

        def walk(g, x, y, d, s):
            R, C = len(g), len(g[0])
            ln, best = 0, 0
            while inside(x, y, R, C) and good(g[x][y], s):
                ln += 1
                best = max(best, ln)
                nd, xx, yy, ss, tmp = (d + 1) % 4, x + dx[(d + 1) % 4], y + dy[(d + 1) % 4], s + 1, 0
                while inside(xx, yy, R, C) and good(g[xx][yy], ss):
                    tmp += 1
                    xx += dx[nd]
                    yy += dy[nd]
                    ss += 1
                best = max(best, ln + tmp)
                x += dx[d]
                y += dy[d]
                s += 1
            return best

        R, C = len(grid), len(grid[0])
        res = 0
        for i in range(R):
            for j in range(C):
                if grid[i][j] == 1:
                    for d in range(4):
                        res = max(res, walk(grid, i, j, d, 0))
        return res
