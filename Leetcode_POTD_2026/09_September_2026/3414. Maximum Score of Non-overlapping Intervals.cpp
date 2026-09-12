class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<long long,4>> sortedRange(n);
        for (int i = 0; i < n; i++)
            sortedRange[i] = {intervals[i][1], intervals[i][0], intervals[i][2], i};
        sort(sortedRange.begin(), sortedRange.end(), [](auto& a, auto& b){ return a[0] < b[0]; });

        vector<long long> rightVals(n);
        for (int i = 0; i < n; i++) rightVals[i] = sortedRange[i][0];

        vector<vector<long long>> bestSum(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> bestIdx(n + 1, vector<vector<int>>(5));

        for (int i = 1; i <= n; i++) {
            long long leftBound = sortedRange[i - 1][1];
            long long weight = sortedRange[i - 1][2];
            int origIdx = sortedRange[i - 1][3];

            int prevCount = lower_bound(rightVals.begin(), rightVals.begin() + (i - 1), leftBound) - rightVals.begin();

            for (int k = 1; k <= 4; k++) {
                bestSum[i][k] = bestSum[i - 1][k];
                bestIdx[i][k] = bestIdx[i - 1][k];

                long long candSum = bestSum[prevCount][k - 1] + weight;
                vector<int> candIdx = bestIdx[prevCount][k - 1];
                candIdx.push_back(origIdx);
                sort(candIdx.begin(), candIdx.end());

                if (candSum > bestSum[i][k] || (candSum == bestSum[i][k] && candIdx < bestIdx[i][k])) {
                    bestSum[i][k] = candSum;
                    bestIdx[i][k] = candIdx;
                }
            }
        }

        return bestIdx[n][4];
    }
};
