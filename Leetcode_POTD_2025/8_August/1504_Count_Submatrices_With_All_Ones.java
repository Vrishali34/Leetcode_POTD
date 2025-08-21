class Solution {
    public int numSubmat(int[][] mat) {
        int rows = mat.length;
        int cols = mat[0].length;
        int[][] heights = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    heights[i][j] = (i > 0) ? heights[i - 1][j] + 1 : 1;
                }
            }
        }
        int total = 0;
        for (int i = 0; i < rows; i++) {
            java.util.Stack<int[]> stack = new java.util.Stack<>();
            int count = 0;
            for (int j = 0; j < cols; j++) {
                int h = heights[i][j];
                while (!stack.isEmpty() && stack.peek()[0] > h) {
                    stack.pop();
                }
                int prev_count = stack.isEmpty() ? 0 : stack.peek()[1];
                int current_count = h * (j - (stack.isEmpty() ? -1 : stack.peek()[2])) + prev_count;
                total += current_count;
                stack.push(new int[]{h, current_count, j});
            }
        }
        return total;
    }
}
