class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> nodalAltitude(n);
        for (int i = 0; i < n; ++i) nodalAltitude[i] = {nums[i], i};
        sort(nodalAltitude.begin(), nodalAltitude.end());
        vector<int> sequenceMap(n);
        for (int i = 0; i < n; ++i) sequenceMap[nodalAltitude[i].second] = i;
        vector<int> farthestVantage(n);
        int windowRight = 0;
        for (int i = 0; i < n; ++i) {
            while (windowRight + 1 < n && nodalAltitude[windowRight + 1].first - nodalAltitude[i].first <= maxDiff) {
                windowRight++;
            }
            farthestVantage[i] = max(windowRight, i);
        }
        vector<vector<int>> leapMatrix(n, vector<int>(18));
        for (int i = 0; i < n; ++i) leapMatrix[i][0] = farthestVantage[i];
        for (int j = 1; j < 18; ++j) {
            for (int i = 0; i < n; ++i) {
                leapMatrix[i][j] = leapMatrix[leapMatrix[i][j - 1]][j - 1];
            }
        }
        vector<int> queryResponses;
        for (const auto& singleQuery : queries) {
            int startNode = sequenceMap[singleQuery[0]];
            int targetNode = sequenceMap[singleQuery[1]];
            if (startNode > targetNode) swap(startNode, targetNode);
            if (startNode == targetNode) {
                queryResponses.push_back(0);
                continue;
            }
            if (farthestVantage[startNode] == startNode) {
                queryResponses.push_back(-1);
                continue;
            }
            int currentPosition = startNode;
            int totalHops = 0;
            for (int j = 17; j >= 0; --j) {
                if (leapMatrix[currentPosition][j] < targetNode) {
                    totalHops += (1 << j);
                    currentPosition = leapMatrix[currentPosition][j];
                }
            }
            if (farthestVantage[currentPosition] < targetNode) queryResponses.push_back(-1);
            else queryResponses.push_back(totalHops + 1);
        }
        return queryResponses;
    }
};
