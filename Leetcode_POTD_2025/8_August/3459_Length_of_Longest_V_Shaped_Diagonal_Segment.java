class Solution {
    int[] dx = {-1, -1, 1, 1}, dy = {-1, 1, 1, -1};

    boolean inside(int x, int y, int R, int C) {
        return x >= 0 && y >= 0 && x < R && y < C;
    }

    boolean good(int v, int s) {
        return s == 0 ? v == 1 : (s % 2 == 1 ? v == 2 : v == 0);
    }

    int walk(int[][] g, int x, int y, int d, int s) {
        int R = g.length, C = g[0].length, len = 0, best = 0;
        while (inside(x, y, R, C) && good(g[x][y], s)) {
            len++; 
            best = Math.max(best, len);
            int nd = (d + 1) % 4, xx = x + dx[nd], yy = y + dy[nd], ss = s + 1, tmp = 0;
            while (inside(xx, yy, R, C) && good(g[xx][yy], ss)) {
                tmp++; xx += dx[nd]; yy += dy[nd]; ss++;
            }
            best = Math.max(best, len + tmp);
            x += dx[d]; y += dy[d]; s++;
        }
        return best;
    }

    public int lenOfVDiagonal(int[][] g) {
        int R = g.length, C = g[0].length, res = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (g[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        res = Math.max(res, walk(g, i, j, d, 0));
                    }
                }
            }
        }
        return res;
    }
}
