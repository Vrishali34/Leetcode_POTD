class Solution {
    public int minOperations(int[] w) {
        int x = 0, n = w.length;
        for (int i = 0; i < n - 2; i++)
            if (w[i] == 0) { w[i] ^= 1; w[i + 1] ^= 1; w[i + 2] ^= 1; x++; }
        return Arrays.stream(w).anyMatch(v -> v == 0) ? -1 : x;
    }
}
