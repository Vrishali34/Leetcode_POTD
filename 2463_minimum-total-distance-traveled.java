class Solution {
    public long minimumTotalDistance(List<Integer> robots, int[][] factories) {
        Collections.sort(robots);
        Arrays.sort(factories, Comparator.comparingInt(a -> a[0]));
        int nr = robots.size(), nf = factories.length;
        long inf = 1L << 40;
        long[][][] dp = new long[100][100][101];
        for (int i = 0; i < nr; i++)
            for (int j = 0; j < nf; j++)
                Arrays.fill(dp[i][j], inf);
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nf; j++) {
                int xr = robots.get(i), xf = factories[j][0], cap = factories[j][1];
                long prev = (j == 0) ? inf : dp[i][j - 1][0];
                dp[i][j][cap] = prev;
                for (int k = cap - 1; k >= 0; k--) {
                    long calc = (i == 0) ? Math.abs(xr - xf) : Math.abs(xr - xf) + dp[i - 1][j][k + 1];
                    dp[i][j][k] = Math.min(prev, calc);
                }
            }
        }
        return dp[nr - 1][nf - 1][0];
    }
}
