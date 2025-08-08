class Solution {
    private double[][] memo;
    public double soupServings(int n) {
        if (n >= 4800) return 1.0;
        int size = (n + 24) / 25;
        memo = new double[size + 1][size + 1];
        return calcProb(size, size);
    }
    private double calcProb(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (memo[a][b] > 0) return memo[a][b];
        double res = 0.25 * (calcProb(a - 4, b) +
                             calcProb(a - 3, b - 1) +
                             calcProb(a - 2, b - 2) +
                             calcProb(a - 1, b - 3));
        return memo[a][b] = res;
    }
}
