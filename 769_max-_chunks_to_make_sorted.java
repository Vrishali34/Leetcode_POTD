class Solution {
    public int maxChunksToSorted(int[] a) {
        int b = 0, c = 0;
        for (int i = 0; i < a.length; i++) {
            c += a[i] - i;
            b += (c == 0) ? 1 : 0;
        }
        return b;
    }
}
