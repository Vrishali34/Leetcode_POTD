class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> output(queries.size());
        sort(items.begin(), items.end(), [](auto& a, auto& b) { return a[0] < b[0]; });
        int currBest = items[0][1];
        for (int i = 0; i < items.size(); ++i) {
            currBest = max(currBest, items[i][1]);
            items[i][1] = currBest;
        }
        for (int i = 0; i < queries.size(); ++i) {
            output[i] = maxAtPrice(items, queries[i]);
        }
        return output;
    }

    int maxAtPrice(vector<vector<int>>& items, int priceThreshold) {
        int start = 0, end = items.size() - 1, best = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (items[mid][0] > priceThreshold) {
                end = mid - 1;
            } else {
                best = max(best, items[mid][1]);
                start = mid + 1;
            }
        }
        return best;
    }
};
