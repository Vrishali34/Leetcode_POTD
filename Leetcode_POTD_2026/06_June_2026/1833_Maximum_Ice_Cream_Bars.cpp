class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_val = 0, total_bars = 0;
        for (int c : costs) if (c > max_val) max_val = c;
        vector<int> price_freq(max_val + 1, 0);
        for (int c : costs) price_freq[c]++;
        for (int p = 1; p <= max_val && coins >= p; ++p) {
            if (!price_freq[p]) continue;
            int buy_count = min(price_freq[p], coins / p);
            total_bars += buy_count;
            coins -= buy_count * p;
        }
        return total_bars;
    }
};
