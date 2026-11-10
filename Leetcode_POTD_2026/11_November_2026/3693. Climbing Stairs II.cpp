class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> minCost(n + 1, INT_MAX);
        minCost[0] = 0;
        for (int step = 1; step <= n; step++)
            for (int jump = 1; jump <= 3 && jump <= step; jump++)
                minCost[step] = min(minCost[step], minCost[step - jump] + costs[step - 1] + jump * jump);
        return minCost[n];
    }
};
