class Solution {
    public int minimumSum(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int minAreaSum = Integer.MAX_VALUE;

        // Case 1: Three horizontal splits
        for (int r1 = 0; r1 < rows - 1; r1++) {
            for (int r2 = r1 + 1; r2 < rows - 1; r2++) {
                int area1 = calculateArea(grid, 0, 0, r1, cols - 1);
                int area2 = calculateArea(grid, r1 + 1, 0, r2, cols - 1);
                int area3 = calculateArea(grid, r2 + 1, 0, rows - 1, cols - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    minAreaSum = Math.min(minAreaSum, area1 + area2 + area3);
                }
            }
        }

        // Case 2: Three vertical splits
        for (int c1 = 0; c1 < cols - 1; c1++) {
            for (int c2 = c1 + 1; c2 < cols - 1; c2++) {
                int area1 = calculateArea(grid, 0, 0, rows - 1, c1);
                int area2 = calculateArea(grid, 0, c1 + 1, rows - 1, c2);
                int area3 = calculateArea(grid, 0, c2 + 1, rows - 1, cols - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    minAreaSum = Math.min(minAreaSum, area1 + area2 + area3);
                }
            }
        }

        // Case 3: One horizontal, then one vertical split
        for (int r_split = 0; r_split < rows - 1; r_split++) {
            for (int c_split = 0; c_split < cols - 1; c_split++) {
                int area1 = calculateArea(grid, 0, 0, r_split, cols - 1);
                int area2 = calculateArea(grid, r_split + 1, 0, rows - 1, c_split);
                int area3 = calculateArea(grid, r_split + 1, c_split + 1, rows - 1, cols - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    minAreaSum = Math.min(minAreaSum, area1 + area2 + area3);
                }
            }
        }
        // Symmetrical horizontal-vertical split
        for (int r_split = 0; r_split < rows - 1; r_split++) {
            for (int c_split = 0; c_split < cols - 1; c_split++) {
                int area1 = calculateArea(grid, r_split + 1, 0, rows - 1, cols - 1);
                int area2 = calculateArea(grid, 0, 0, r_split, c_split);
                int area3 = calculateArea(grid, 0, c_split + 1, r_split, cols - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    minAreaSum = Math.min(minAreaSum, area1 + area2 + area3);
                }
            }
        }

        // Case 4: One vertical, then one horizontal split
        for (int c_split = 0; c_split < cols - 1; c_split++) {
            for (int r_split = 0; r_split < rows - 1; r_split++) {
                int area1 = calculateArea(grid, 0, 0, rows - 1, c_split);
                int area2 = calculateArea(grid, 0, c_split + 1, r_split, cols - 1);
                int area3 = calculateArea(grid, r_split + 1, c_split + 1, rows - 1, cols - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    minAreaSum = Math.min(minAreaSum, area1 + area2 + area3);
                }
            }
        }
        // Symmetrical vertical-horizontal split
        for (int c_split = 0; c_split < cols - 1; c_split++) {
            for (int r_split = 0; r_split < rows - 1; r_split++) {
                int area1 = calculateArea(grid, 0, c_split + 1, rows - 1, cols - 1);
                int area2 = calculateArea(grid, 0, 0, r_split, c_split);
                int area3 = calculateArea(grid, r_split + 1, 0, rows - 1, c_split);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    minAreaSum = Math.min(minAreaSum, area1 + area2 + area3);
                }
            }
        }
        
        return minAreaSum;
    }

    private int calculateArea(int[][] grid, int r1, int c1, int r2, int c2) {
        int minRow = r2 + 1, maxRow = -1;
        int minCol = c2 + 1, maxCol = -1;
        boolean foundOne = false;
        
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                if (grid[i][j] == 1) {
                    minRow = Math.min(minRow, i);
                    maxRow = Math.max(maxRow, i);
                    minCol = Math.min(minCol, j);
                    maxCol = Math.max(maxCol, j);
                    foundOne = true;
                }
            }
        }
        
        if (!foundOne) {
            return 0;
        }
        
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
}
