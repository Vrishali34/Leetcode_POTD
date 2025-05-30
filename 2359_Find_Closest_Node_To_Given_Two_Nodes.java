class Solution {
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int vtxCt = edges.length;

        int[] pathA = new int[vtxCt];
        int[] pathB = new int[vtxCt];
        java.util.Arrays.fill(pathA, -1);
        java.util.Arrays.fill(pathB, -1);

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
                int currentMax = Math.max(pathA[i], pathB[i]);
                if (bestVtx == -1 || currentMax < minOverallMax) {
                    minOverallMax = currentMax;
                    bestVtx = i;
                } else if (currentMax == minOverallMax) {
                    bestVtx = Math.min(bestVtx, i);
                }
            }
        }
        return bestVtx;
    }
}
