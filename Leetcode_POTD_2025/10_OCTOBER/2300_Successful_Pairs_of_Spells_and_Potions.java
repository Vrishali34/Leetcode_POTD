class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) { 
        int m = potions.length;
        int n = spells.length;
        int[] results = new int[n];
        Arrays.sort(potions);
        for (int i = 0; i < n; i++) {
            long min_power = (success + spells[i] - 1) / spells[i];
            int low = 0, high = m;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (potions[mid] < min_power) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            results[i] = m - low;
        }
        return results;
    }
}
