class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> factorCnt(n + 1, 0);
        for (auto& item : items) factorCnt[item[0]]++;
        vector<pair<int, int>> priceGain;
        int minPrice = INT_MAX;
        for (auto& item : items) {
            int factorVal = item[0], gainCnt = -1;
            for (int m = factorVal; m <= n; m += factorVal) gainCnt += factorCnt[m];
            priceGain.push_back({item[1], gainCnt});
            minPrice = min(minPrice, item[1]);
        }
        sort(priceGain.begin(), priceGain.end());
        long long spent = 0, boosted = 0, best = budget / minPrice;
        for (auto& [priceVal, gainCnt] : priceGain) {
            if (priceVal >= 2LL * minPrice) break;
            long long take = min<long long>(gainCnt, (budget - spent) / priceVal);
            spent += take * priceVal;
            boosted += take;
            best = max(best, 2 * boosted + (budget - spent) / minPrice);
        }
        return best;
    }
};
