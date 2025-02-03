class Solution {
    public int longestMonotonicSubarray(int[] X) {
        int top = 1, up = 1, down = 1;
        for (int j = 1; j < X.length; j++) {
            if (X[j] > X[j - 1]) { up++; down = 1; }
            else if (X[j] < X[j - 1]) { down++; up = 1; }
            else up = down = 1;
            top = Math.max(top, Math.max(up, down));
        }
        return top;
    }
}
