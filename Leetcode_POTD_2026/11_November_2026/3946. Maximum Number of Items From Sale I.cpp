class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> factorFreq(1501, 0), maxGain(budget + 1, 0);
        int minPrice = INT_MAX, maxTotal = 0;
        for (auto& item : items) {
            factorFreq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }
        for (auto& item : items) {
            int factorVal = item[0], priceVal = item[1], multCnt = 0;
            for (int m = factorVal; m <= 1500; m += factorVal) multCnt += factorFreq[m];
            for (int b = budget; b >= priceVal; b--)
                maxGain[b] = max(maxGain[b], maxGain[b - priceVal] + multCnt);
        }
        for (int b = 0; b <= budget; b++)
            maxTotal = max(maxTotal, maxGain[b] + (budget - b) / minPrice);
        return maxTotal;
    }
};
