class Solution {
    public int minCost(int[][] g) {
        Deque<int[]> d = new ArrayDeque<>();
        int[][] t = new int[g.length][g[0].length];
        for (int[] r : t) Arrays.fill(r, Integer.MAX_VALUE);
        int[][] z = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        d.add(new int[]{0, 0});
        t[0][0] = 0;
        while (!d.isEmpty()) {
            int[] u = d.poll();
            for (int i = 0; i < 4; i++) {
                int x = u[0] + z[i][0], y = u[1] + z[i][1];
                if (x >= 0 && x < g.length && y >= 0 && y < g[0].length) {
                    int c = t[u[0]][u[1]] + (g[u[0]][u[1]] == i + 1 ? 0 : 1);
                    if (c < t[x][y]) {
                        t[x][y] = c;
                        if (g[u[0]][u[1]] == i + 1) d.addFirst(new int[]{x, y});
                        else d.addLast(new int[]{x, y});
                    }
                }
            }
        }
        return t[g.length - 1][g[0].length - 1];
    }
}
