class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long pairCost = min(costBoth, cost1 + cost2);
        long long commonNeed = min(need1, need2);
        return commonNeed * pairCost + (long long)(need1 - commonNeed) * min(cost1, costBoth) + (long long)(need2 - commonNeed) * min(cost2, costBoth);
    }
};
