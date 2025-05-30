class Solution {
public:
    int closestMeetingNode(std::vector<int>& edges, int node1, int node2) {
        int vtxCt = edges.size();

        std::vector<int> pathA(vtxCt, -1);
        std::vector<int> pathB(vtxCt, -1);

        int currNode = node1;
        int dist = 0;
        while (currNode != -1 && pathA[currNode] == -1) {
            pathA[currNode] = dist++;
            currNode = edges[currNode];
        }

        currNode = node2;
        dist = 0;
        while (currNode != -1 && pathB[currNode] == -1) {
            pathB[currNode] = dist++;
            currNode = edges[currNode];
        }

        int minOverallMax = -1;
        int bestVtx = -1;

        for (int i = 0; i < vtxCt; ++i) {
            if (pathA[i] != -1 && pathB[i] != -1) {
                int currentMax = std::max(pathA[i], pathB[i]);
                if (bestVtx == -1 || currentMax < minOverallMax) {
                    minOverallMax = currentMax;
                    bestVtx = i;
                } else if (currentMax == minOverallMax) {
                    bestVtx = std::min(bestVtx, i);
                }
            }
        }
        return bestVtx;
    }
};
