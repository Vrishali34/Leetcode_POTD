class Solution {
public:
    int n;
    vector<int> suffixSum;
    vector<vector<int>> memo;
    int solve(int idx, int cap) {
        if (idx + 2 * cap >= n) return suffixSum[idx];
        if (memo[idx][cap] != -1) return memo[idx][cap];
        int bestGrab = 0;
        for (int take = 1; take <= 2 * cap; take++) {
            int rivalGet = solve(idx + take, max(cap, take));
            bestGrab = max(bestGrab, suffixSum[idx] - rivalGet);
        }
        return memo[idx][cap] = bestGrab;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffixSum.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) suffixSum[i] = suffixSum[i + 1] + piles[i];
        memo.assign(n + 1, vector<int>(n + 1, -1));
        return solve(0, 1);
    }
};
