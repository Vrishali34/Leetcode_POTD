class Solution {
    public int maxAbsoluteSum(int[] p) {
        int high = 0, low = 0, temp = 0;
        for (int n : p) {
            temp += n;
            high = Math.max(high, temp);
            low = Math.min(low, temp);
        }
        return high - low;
    }
}
