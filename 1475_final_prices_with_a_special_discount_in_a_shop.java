class Solution {
    public int[] finalPrices(int[] p) {
        int n = p.length, res[] = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = p[i];
            for (int j = i + 1; j < n; j++) {
                if (p[j] <= p[i]) {
                    res[i] = p[i] - p[j];
                    break;
                }
            }
        }
        return res;
    }
}
