class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) {
            return 1.0;
        }
        std::vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double window_sum = 1.0;
        double total_prob = 0.0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = window_sum / maxPts;
            if (i < k) {
                window_sum += dp[i];
            }
            if (i >= maxPts) {
                window_sum -= dp[i - maxPts];
            }
            if (i >= k) {
                total_prob += dp[i];
            }
        }
        return total_prob;
    }
};
