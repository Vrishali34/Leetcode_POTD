class Solution {
    public int findMaxFish(int[][] grid) {
        int maxFish = 0, rows = grid.length, cols = grid[0].length;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (grid[i][j] > 0)
                    maxFish = Math.max(maxFish, bfs(grid, i, j, rows, cols));
        return maxFish;
    }

    private int bfs(int[][] g, int x, int y, int r, int c) {
        int fishCount = 0;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {x, y});
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int i = cell[0], j = cell[1];
            if (g[i][j] > 0) {
                fishCount += g[i][j];
                g[i][j] = 0;
                if (i > 0) q.add(new int[] {i - 1, j});
                if (i + 1 < r) q.add(new int[] {i + 1, j});
                if (j > 0) q.add(new int[] {i, j - 1});
                if (j + 1 < c) q.add(new int[] {i, j + 1});
            }
        }
        return fishCount;
    }
}
