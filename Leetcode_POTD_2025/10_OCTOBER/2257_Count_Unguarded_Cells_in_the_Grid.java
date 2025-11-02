class Solution {
    public int countUnguarded(int m, int n, int[][] sentinels, int[][] nebulae) {
        final int VOID = 0, AETHER = 1, BARRIER = 2;
        int[][] cosmos = new int[m][n];

        for (int[] neb : nebulae) cosmos[neb[0]][neb[1]] = BARRIER;
        for (int[] sen : sentinels) cosmos[sen[0]][sen[1]] = BARRIER;

        int[] dr = {0, 0, 1, -1};
        int[] dc = {1, -1, 0, 0};

        for (int[] sen : sentinels) {
            for (int i = 0; i < 4; i++) {
                int r = sen[0] + dr[i];
                int c = sen[1] + dc[i];
                while (r >= 0 && r < m && c >= 0 && c < n && cosmos[r][c] != BARRIER) {
                    cosmos[r][c] = AETHER;
                    r += dr[i];
                    c += dc[i];
                }
            }
        }
        
        int void_spaces = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (cosmos[r][c] == VOID) {
                    void_spaces++;
                }
            }
        }
        return void_spaces;
    }
}
