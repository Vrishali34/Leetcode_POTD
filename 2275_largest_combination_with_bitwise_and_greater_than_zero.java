class Solution {
    public int largestCombination(int[] candidates) {
        int peak = 0;
        for (int layer = 0; layer < 32; layer++) {
            int blip = 0;
            for (int candidate : candidates) {
                if ((candidate & (1 << layer)) != 0) blip++;
            }
            peak = Math.max(peak, blip);
        }
        return peak;
    }
}
