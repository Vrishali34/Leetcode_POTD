class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int sz = prices.size(), half_k = k / 2;
        long long static_sum = 0, sliding_mod = 0;
        for (int i = 0; i < sz; ++i) static_sum += 1LL * prices[i] * strategy[i];
        for (int i = 0; i < k; ++i) sliding_mod += 1LL * prices[i] * ((i < half_k ? 0 : 1) - strategy[i]);
        long long best_mod = max(0LL, sliding_mod);
        for (int j = k; j < sz; ++j) {
            sliding_mod -= 1LL * prices[j - k] * (0 - strategy[j - k]);
            sliding_mod -= 1LL * prices[j - half_k] * (1 - 0);
            sliding_mod += 1LL * prices[j] * (1 - strategy[j]);
            best_mod = max(best_mod, sliding_mod);
        }
        return static_sum + best_mod;
    }
};
