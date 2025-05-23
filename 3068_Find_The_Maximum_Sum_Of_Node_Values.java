class Solution {
    public long maximumValueSum(int[] eL, int iN, int[][] bT) {
        long pS = 0;
        int tC = 0;
        long lP = 2_000_000_007L;
        for (int qV : eL) {
            long xV = qV ^ iN;
            pS += Math.max(qV, xV);
            if (xV > qV) {
                tC++;
            }
            lP = Math.min(lP, Math.abs(qV - xV));
        }
        if (tC % 2 == 0) {
            return pS;
        }
        return pS - lP;
    }
}
