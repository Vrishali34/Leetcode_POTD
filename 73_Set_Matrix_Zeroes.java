class Solution {
    public void setZeroes(int[][] m) {
        int r = m.length, c = m[0].length;
        boolean row = false, col = false;
        for (int i = 0; i < r; i++) if (m[i][0] == 0) col = true;
        for (int j = 0; j < c; j++) if (m[0][j] == 0) row = true;
        for (int i = 1; i < r; i++)
            for (int j = 1; j < c; j++)
                if (m[i][j] == 0) m[i][0] = m[0][j] = 0;
        for (int i = 1; i < r; i++)
            for (int j = 1; j < c; j++)
                if (m[i][0] == 0 || m[0][j] == 0) m[i][j] = 0;
        if (row) for (int j = 0; j < c; j++) m[0][j] = 0;
        if (col) for (int i = 0; i < r; i++) m[i][0] = 0;
    }
}
