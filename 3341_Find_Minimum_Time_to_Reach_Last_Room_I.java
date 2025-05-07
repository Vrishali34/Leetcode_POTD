class Z implements Comparable<Z> {
    int x, y, t;
    Z(int x, int y, int t) { this.x = x; this.y = y; this.t = t; }
    public int compareTo(Z o) { return this.t - o.t; }
}

class Solution {
    public int minTimeToReach(int[][] mt) {
        int r = mt.length, c = mt[0].length;
        int[][] d = new int[r][c];
        for (int[] row : d) Arrays.fill(row, Integer.MAX_VALUE);

        int[] dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        PriorityQueue<Z> pq = new PriorityQueue<>();
        d[0][0] = 0;
        pq.offer(new Z(0, 0, 0));

        while (!pq.isEmpty()) {
            Z p = pq.poll();
            int i = p.x, j = p.y, t = p.t;
            if (i == r - 1 && j == c - 1) return t;
            if (d[i][j] < t) continue;
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && nj >= 0 && ni < r && nj < c) {
                    int time = t + 1, wait = Math.max(0, mt[ni][nj] - d[i][j]);
                    time += wait;
                    if (time < d[ni][nj]) {
                        d[ni][nj] = time;
                        pq.offer(new Z(ni, nj, time));
                    }
                }
            }
        }
        return -1;
    }
}
