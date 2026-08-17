class Solution {
public:
    vector<vector<int>> bestScore;
    vector<int> flowSum;
    int solve(int bankL, int bankR) {
        if (bankL == bankR) return 0;
        if (bestScore[bankL][bankR] != -1) return bestScore[bankL][bankR];
        int topScore = 0;
        for (int split = bankL; split < bankR; split++) {
            int leftSum = flowSum[split] - (bankL ? flowSum[bankL - 1] : 0);
            int rightSum = flowSum[bankR] - flowSum[split];
            if (leftSum < rightSum) topScore = max(topScore, leftSum + solve(bankL, split));
            else if (leftSum > rightSum) topScore = max(topScore, rightSum + solve(split + 1, bankR));
            else topScore = max({topScore, leftSum + solve(bankL, split), rightSum + solve(split + 1, bankR)});
        }
        return bestScore[bankL][bankR] = topScore;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int pebbleCount = stoneValue.size();
        flowSum.assign(pebbleCount, 0);
        flowSum[0] = stoneValue[0];
        for (int i = 1; i < pebbleCount; i++) flowSum[i] = flowSum[i - 1] + stoneValue[i];
        bestScore.assign(pebbleCount, vector<int>(pebbleCount, -1));
        return solve(0, pebbleCount - 1);
    }
};
