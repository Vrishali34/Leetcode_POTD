class Solution {
    public int minTimeToReach(int[][] z) {
        int r = z.length, c = z[0].length;
        boolean[][] v = new boolean[r][c];
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        q.offer(new int[]{0, 0, 0, 1});
        int[][] d = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.isEmpty()) {
            int[] u = q.poll();
            int t = u[0], x = u[1], y = u[2], s = u[3];
            if (x == r-1 && y == c-1) return t;
            if (v[x][y]) continue;
            v[x][y] = true;
            for (int[] f : d) {
                int nx = x + f[0], ny = y + f[1];
                if (nx >= 0 && ny >= 0 && nx < r && ny < c && !v[nx][ny])
                    q.offer(new int[]{Math.max(t, z[nx][ny]) + s, nx, ny, 3 - s});
            }
        }
        return -1;
    }
}
