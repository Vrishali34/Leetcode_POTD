class Solution {
    public int maxScoreSightseeingPair(int[] a) {
        int maxSum = 0, maxI = a[0];
        for (int j = 1; j < a.length; j++) {
            maxSum = Math.max(maxSum, maxI + a[j] - j);
            maxI = Math.max(maxI, a[j] + j);
        }
        return maxSum;
    }
}
