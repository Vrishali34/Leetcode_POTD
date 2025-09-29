class Solution {
public:
    int minScoreTriangulation(std::vector<int>& values) {
        int vert = values.size();
        std::vector<std::vector<int>> dp(vert, std::vector<int>(vert, 0));
        for (int len = 3; len <= vert; ++len) {
            for (int i = 0; i <= vert - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    int curr_prod = values[i] * values[k] * values[j];
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j] + curr_prod);
                }
            }
        }
        return dp[0][vert - 1];
    }
};
