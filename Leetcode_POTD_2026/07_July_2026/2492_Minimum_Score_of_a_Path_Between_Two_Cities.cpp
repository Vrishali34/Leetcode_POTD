class Solution {
public:
    int minScore(int cityCount, vector<vector<int>>& roadNetwork) {
        vector<vector<pair<int, int>>> adjList(cityCount + 1);
        for (const auto& lane : roadNetwork) {
            adjList[lane[0]].push_back({lane[1], lane[2]});
            adjList[lane[1]].push_back({lane[0], lane[2]});
        }
        int minRouteCost = 1e9;
        vector<bool> seenCity(cityCount + 1, false);
        queue<int> taskQueue;
        taskQueue.push(1);
        seenCity[1] = true;
        while (!taskQueue.empty()) {
            int currentCity = taskQueue.front();
            taskQueue.pop();
            for (const auto& edge : adjList[currentCity]) {
                int nextCity = edge.first;
                int routeWeight = edge.second;
                minRouteCost = min(minRouteCost, routeWeight);
                if (!seenCity[nextCity]) {
                    seenCity[nextCity] = true;
                    taskQueue.push(nextCity);
                }
            }
        }
        return minRouteCost;
    }
};
