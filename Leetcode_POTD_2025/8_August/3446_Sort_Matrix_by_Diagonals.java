class Solution {
    public int[][] sortMatrix(int[][] grid) {
        int n = grid.length;
        Map<Integer, List<Integer>> bottomLeft = new HashMap<>();
        Map<Integer, List<Integer>> topRight = new HashMap<>();

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r >= c) {
                    bottomLeft.computeIfAbsent(r - c, k -> new ArrayList<>()).add(grid[r][c]);
                } else {
                    topRight.computeIfAbsent(r - c, k -> new ArrayList<>()).add(grid[r][c]);
                }
            }
        }

        for (List<Integer> list : bottomLeft.values()) {
            Collections.sort(list, Collections.reverseOrder());
        }

        for (List<Integer> list : topRight.values()) {
            Collections.sort(list);
        }

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (r >= c) {
                    grid[r][c] = bottomLeft.get(r - c).remove(0);
                } else {
                    grid[r][c] = topRight.get(r - c).remove(0);
                }
            }
        }
        return grid;
    }
}
