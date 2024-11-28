import java.util.*;

class Solution {
    public int minimumObstacles(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        Deque<int[]> deque = new ArrayDeque<>();
        int[][] dist = new int[rows][cols];
        for (int[] row : dist) Arrays.fill(row, Integer.MAX_VALUE);
        deque.addFirst(new int[]{0, 0});
        dist[0][0] = 0;

        int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while (!deque.isEmpty()) {
            int[] cell = deque.pollFirst();
            int x = cell[0], y = cell[1];
            for (int[] dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    int newDist = dist[x][y] + grid[nx][ny];
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        if (grid[nx][ny] == 0) deque.addFirst(new int[]{nx, ny});
                        else deque.addLast(new int[]{nx, ny});
                    }
                }
            }
        }
        return dist[rows - 1][cols - 1];
    }
}
