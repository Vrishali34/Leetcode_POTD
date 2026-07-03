class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int nodeCount = online.size();
        vector<vector<pair<int,int>>> pathGraph(nodeCount);
        vector<int> entryCount(nodeCount), topoOrder;

        for (auto &edge : edges) {
            pathGraph[edge[0]].push_back({edge[1], edge[2]});
            ++entryCount[edge[1]];
        }

        queue<int> zeroEntry;
        for (int node = 0; node < nodeCount; node++)
            if (!entryCount[node]) zeroEntry.push(node);

        while (!zeroEntry.empty()) {
            int fromNode = zeroEntry.front();
            zeroEntry.pop();
            topoOrder.push_back(fromNode);
            for (auto &[nextNode, edgeCost] : pathGraph[fromNode])
                if (!--entryCount[nextNode]) zeroEntry.push(nextNode);
        }

        auto canReach = [&](int minScore) {
            const long long infCost = 4e18;
            vector<long long> reachCost(nodeCount, infCost);
            reachCost[0] = 0;

            for (int fromNode : topoOrder) {
                if (reachCost[fromNode] == infCost) continue;
                if (fromNode && fromNode != nodeCount - 1 && !online[fromNode]) continue;

                for (auto &[nextNode, edgeCost] : pathGraph[fromNode]) {
                    if (edgeCost < minScore) continue;
                    if (nextNode != nodeCount - 1 && !online[nextNode]) continue;
                    reachCost[nextNode] = min(reachCost[nextNode], reachCost[fromNode] + edgeCost);
                }
            }
            return reachCost.back() <= k;
        };

        int lowScore = 0, highScore = 1e9, bestScore = -1;
        while (lowScore <= highScore) {
            int midScore = lowScore + ((highScore - lowScore) >> 1);
            if (canReach(midScore))
                bestScore = midScore, lowScore = midScore + 1;
            else
                highScore = midScore - 1;
        }
        return bestScore;
    }
};
