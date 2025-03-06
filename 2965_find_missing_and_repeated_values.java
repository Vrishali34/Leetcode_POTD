class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length, N = n * n;
        long sumExpected = (long) N * (N + 1) / 2;
        long sumSquareExpected = (long) N * (N + 1) * (2 * N + 1) / 6;
        long sumActual = 0, sumSquareActual = 0;

        for (int[] row : grid) {
            for (int num : row) {
                sumActual += num;
                sumSquareActual += (long) num * num;
            }
        }

        long diff1 = sumActual - sumExpected;  // a - b
        long diff2 = sumSquareActual - sumSquareExpected;  // a^2 - b^2

        int repeated = (int) ((diff1 + diff2 / diff1) / 2);
        int missing = (int) (repeated - diff1);

        return new int[]{repeated, missing};
    }
}
