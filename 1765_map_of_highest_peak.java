class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int rows = isWater.length, cols = isWater[0].length;
        int[][] heights = new int[rows][cols];
        Queue<int[]> queue = new LinkedList<>();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (isWater[i][j] == 1) {
                    heights[i][j] = 0;
                    queue.offer(new int[]{i, j});
                } else {
                    heights[i][j] = -1;
                }
            }
        }
        
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int r = cell[0], c = cell[1];
            
            for (int[] dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && heights[nr][nc] == -1) {
                    heights[nr][nc] = heights[r][c] + 1;
                    queue.offer(new int[]{nr, nc});
                }
            }
        }
        
        return heights;
    }
}
