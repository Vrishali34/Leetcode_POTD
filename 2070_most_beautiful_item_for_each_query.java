class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        int[] results = new int[queries.length];
        Arrays.sort(items, (a, b) -> Integer.compare(a[0], b[0]));
        int currentMax = items[0][1];
        for (int i = 0; i < items.length; i++) {
            currentMax = Math.max(currentMax, items[i][1]);
            items[i][1] = currentMax;
        }
        for (int i = 0; i < queries.length; i++) {
            results[i] = maxAffordableBeauty(items, queries[i]);
        }
        return results;
    }

    private int maxAffordableBeauty(int[][] items, int limit) {
        int left = 0, right = items.length - 1, bestBeauty = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (items[mid][0] > limit) {
                right = mid - 1;
            } else {
                bestBeauty = Math.max(bestBeauty, items[mid][1]);
                left = mid + 1;
            }
        }
        return bestBeauty;
    }
}
