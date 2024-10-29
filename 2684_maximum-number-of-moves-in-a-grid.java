class Solution {
    public int maxMoves(int[][] g) {
        int r = g.length, c = g[0].length, result = 0;
        int[][] moves = new int[r][c];
        for (int i = 0; i < r; i++) moves[i][0] = 1;
        for (int j = 1; j < c; j++)
            for (int i = 0; i < r; i++) {
                int l = (g[i][j - 1] < g[i][j] && moves[i][j - 1] > 0) ? moves[i][j - 1] + 1 : 0;
                int lu = (i > 0 && g[i - 1][j - 1] < g[i][j] && moves[i - 1][j - 1] > 0) ? moves[i - 1][j - 1] + 1 : 0;
                int ld = (i + 1 < r && g[i + 1][j - 1] < g[i][j] && moves[i + 1][j - 1] > 0) ? moves[i + 1][j - 1] + 1 : 0;
                moves[i][j] = Math.max(l, Math.max(lu, ld));
                result = Math.max(result, moves[i][j] - 1);
            }
        return result;
    }
}
