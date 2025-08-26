class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        long longestDiagSq = 0;
        int greatestArea = 0;
        for (int[] entry : dimensions) {
            long currentDiagSq = (long)entry[0] * entry[0] + (long)entry[1] * entry[1];
            int currentArea = entry[0] * entry[1];
            if (currentDiagSq > longestDiagSq) {
                longestDiagSq = currentDiagSq;
                greatestArea = currentArea;
            } else if (currentDiagSq == longestDiagSq && currentArea > greatestArea) {
                greatestArea = currentArea;
            }
        }
        return greatestArea;
    }
}
