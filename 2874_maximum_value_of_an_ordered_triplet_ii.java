class Solution {
    public long maximumTripletValue(int[] w) {
        int n = w.length;
        int[] rightMax = new int[n];
        rightMax[n - 1] = w[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = Math.max(rightMax[i + 1], w[i]);

        long ans = 0;
        int leftMax = w[0];
        for (int j = 1; j < n - 1; j++) {
            ans = Math.max(ans, (long) (leftMax - w[j]) * rightMax[j + 1]);
            leftMax = Math.max(leftMax, w[j]);
        }
        return ans;
    }
}
