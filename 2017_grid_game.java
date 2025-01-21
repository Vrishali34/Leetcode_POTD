class Solution {  
    public long gridGame(int[][] grid) {  
        int n = grid[0].length;  
        long[] top = new long[n + 1], bot = new long[n + 1];  
        for (int i = 0; i < n; i++) {  
            top[i + 1] = top[i] + grid[0][i];  
            bot[i + 1] = bot[i] + grid[1][i];  
        }  
        long minPoints = Long.MAX_VALUE;  
        for (int i = 0; i < n; i++)  
            minPoints = Math.min(minPoints, Math.max(top[n] - top[i + 1], bot[i]));  
        return minPoints;  
    }  
}  
