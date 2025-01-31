class Solution {
    public int largestIsland(int[][] x) {
        int n = x.length, y = 2, max = 0;
        Map<Integer, Integer> m = new HashMap<>();
        int[][] d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (x[i][j] == 1) {
                    m.put(y, r(x, i, j, y, d));
                    max = Math.max(max, m.get(y++));
                }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (x[i][j] == 0) {
                    Set<Integer> s = new HashSet<>();
                    int cur = 1;
                    for (int[] v : d) {
                        int nx = i + v[0], ny = j + v[1];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && x[nx][ny] > 1) s.add(x[nx][ny]);
                    }
                    for (int k : s) cur += m.get(k);
                    max = Math.max(max, cur);
                }
        return max;
    }

    private int r(int[][] x, int i, int j, int y, int[][] d) {
        if (i < 0 || i >= x.length || j < 0 || j >= x.length || x[i][j] != 1) return 0;
        x[i][j] = y;
        int c = 1;
        for (int[] v : d) c += r(x, i + v[0], j + v[1], y, d);
        return c;
    }
}
