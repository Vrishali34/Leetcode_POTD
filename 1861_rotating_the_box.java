class Solution {
    public char[][] rotateTheBox(char[][] a) {
        int u = a.length, v = a[0].length;
        char[][] w = new char[v][u];
        for (int i = 0; i < u; i++) {
            int q = v - 1;
            for (int j = v - 1; j >= 0; j--) {
                if (a[i][j] == '*') q = j - 1;
                else if (a[i][j] == '#') {
                    a[i][j] = '.';
                    a[i][q--] = '#';
                }
            }
        }
        for (int i = 0; i < u; i++) {
            for (int j = 0; j < v; j++) {
                w[j][u - i - 1] = a[i][j];
            }
        }
        return w;
    }
}
