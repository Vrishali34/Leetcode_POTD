class Solution {
public:
    long long minimumTotalDistance(vector<int>& bots, vector<vector<int>>& fac) {
        sort(bots.begin(), bots.end());
        sort(fac.begin(), fac.end());
        int nb = bots.size(), nf = fac.size();
        const long long inf = 1LL << 40;
        long long dp[100][100][101];
        for (int i = 0; i < nb; ++i)
            for (int j = 0; j < nf; ++j)
                fill(dp[i][j], dp[i][j] + 101, inf);
        for (int i = 0; i < nb; ++i) {
            for (int j = 0; j < nf; ++j) {
                int bPos = bots[i], fPos = fac[j][0], cap = fac[j][1];
                long long pF = (j == 0) ? inf : dp[i][j - 1][0];
                dp[i][j][cap] = pF;
                for (int k = cap - 1; k >= 0; --k) {
                    long long dist = (i == 0) ? abs(bPos - fPos) : abs(bPos - fPos) + dp[i - 1][j][k + 1];
                    dp[i][j][k] = min(pF, dist);
                }
            }
        }
        return dp[nb - 1][nf - 1][0];
    }
};
