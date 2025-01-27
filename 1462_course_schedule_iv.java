class Solution {
    public List<Boolean> checkIfPrerequisite(int c, int[][] p, int[][] q) {
        boolean[][] d = new boolean[c][c];
        for (int[] r : p) d[r[0]][r[1]] = true;
        for (int a = 0; a < c; a++)
            for (int b = 0; b < c; b++)
                for (int e = 0; e < c; e++)
                    d[b][e] |= d[b][a] && d[a][e];
        List<Boolean> ans = new ArrayList<>();
        for (int[] f : q) ans.add(d[f[0]][f[1]]);
        return ans;
    }
}
