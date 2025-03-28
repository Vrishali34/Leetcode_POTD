import java.util.*;

class Solution {
    public int[] maxPoints(int[][] grid, int[] queries) {
        int rows = grid.length, cols = grid[0].length;
        int[] dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

        int n = queries.length;
        int[] res = new int[n];
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) idx[i] = i;

        // Sort queries by value, store original index
        Arrays.sort(idx, Comparator.comparingInt(i -> queries[i]));

        // Min-heap for BFS (value, row, col)
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        boolean[][] vis = new boolean[rows][cols];
        pq.offer(new int[]{grid[0][0], 0, 0});
        vis[0][0] = true;

        int count = 0, qi = 0;

        for (int i = 0; i < n; i++) {
            int query = queries[idx[i]];
            while (!pq.isEmpty() && pq.peek()[0] < query) {
                int[] cur = pq.poll();
                count++;
                int r = cur[1], c = cur[2];

                for (int d = 0; d < 4; d++) {
                    int nr = r + dx[d], nc = c + dy[d];
                    if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && !vis[nr][nc]) {
                        vis[nr][nc] = true;
                        pq.offer(new int[]{grid[nr][nc], nr, nc});
                    }
                }
            }
            res[idx[i]] = count;
        }

        return res;
    }
}
