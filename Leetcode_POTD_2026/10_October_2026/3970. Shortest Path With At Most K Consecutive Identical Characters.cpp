class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& edge : edges) adjList[edge[0]].push_back({edge[1], edge[2]});

        vector<vector<int>> minDist(n, vector<int>(k + 1, INT_MAX));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> minHeap;
        minDist[0][1] = 0;
        minHeap.push({0, 0, 1});

        while (!minHeap.empty()) {
            auto [dist, node, runLen] = minHeap.top();
            minHeap.pop();
            if (dist > minDist[node][runLen]) continue;
            if (node == n - 1) return dist;
            for (auto [nextNode, wt] : adjList[node]) {
                int nextRun = labels[nextNode] == labels[node] ? runLen + 1 : 1;
                if (nextRun > k || dist + wt >= minDist[nextNode][nextRun]) continue;
                minDist[nextNode][nextRun] = dist + wt;
                minHeap.push({dist + wt, nextNode, nextRun});
            }
        }
        return -1;
    }
};
