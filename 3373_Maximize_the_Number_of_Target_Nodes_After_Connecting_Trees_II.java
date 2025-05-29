import java.util.*;

class Solution {

    // Helper method to perform BFS and compute partition counts (even/odd depth from root 0)
    // and store the depth parity for each node.
    private int[] computeBipartitionCounts(int numNodes, List<List<Integer>> adj, int[] nodeDepthParities) {
        Arrays.fill(nodeDepthParities, -1); // Initialize all nodes as unvisited
        Queue<int[]> q = new LinkedList<>(); // Stores {node, depth_parity_from_root}

        // Start BFS from node 0, assuming it's at depth 0 (even parity)
        q.offer(new int[]{0, 0});
        nodeDepthParities[0] = 0;

        int evenDepthCount = 0;
        int oddDepthCount = 0;

        while (!q.isEmpty()) {
            int[] current = q.poll();
            int u = current[0];
            int uParity = current[1];

            if (uParity == 0) {
                evenDepthCount++;
            } else {
                oddDepthCount++;
            }

            for (int v : adj.get(u)) {
                if (nodeDepthParities[v] == -1) { // If neighbor not visited
                    nodeDepthParities[v] = 1 - uParity; // Neighbor's depth parity is opposite
                    q.offer(new int[]{v, 1 - uParity});
                }
            }
        }
        return new int[]{evenDepthCount, oddDepthCount};
    }

    public int[] maxTargetNodes(int[][] edges1, int[][] edges2) {
        int n = edges1.length + 1; // Number of nodes in the first tree
        int m = edges2.length + 1; // Number of nodes in the second tree

        // Build adjacency list for the first tree
        List<List<Integer>> adj1 = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj1.add(new ArrayList<>());
        }
        for (int[] edge : edges1) {
            adj1.get(edge[0]).add(edge[1]);
            adj1.get(edge[1]).add(edge[0]);
        }

        // Build adjacency list for the second tree
        List<List<Integer>> adj2 = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            adj2.add(new ArrayList<>());
        }
        for (int[] edge : edges2) {
            adj2.get(edge[0]).add(edge[1]);
            adj2.get(edge[1]).add(edge[0]);
        }

        // Process Tree 1
        // nodeParitiesT1 will store the depth parity (0 for even, 1 for odd) for each node in Tree 1
        // relative to an arbitrary root (node 0).
        int[] nodeParitiesT1 = new int[n];
        int[] countsT1FromRoot0 = computeBipartitionCounts(n, adj1, nodeParitiesT1);
        int evenPartitionSizeT1 = countsT1FromRoot0[0]; // Number of nodes in T1 with even depth from root 0
        int oddPartitionSizeT1 = countsT1FromRoot0[1];  // Number of nodes in T1 with odd depth from root 0

        // Process Tree 2
        // nodeParitiesT2 will store the depth parity (0 for even, 1 for odd) for each node in Tree 2
        // relative to an arbitrary root (node 0).
        int[] nodeParitiesT2 = new int[m];
        int[] countsT2FromRoot0 = computeBipartitionCounts(m, adj2, nodeParitiesT2);
        int evenPartitionSizeT2 = countsT2FromRoot0[0]; // Number of nodes in T2 with even depth from root 0
        int oddPartitionSizeT2 = countsT2FromRoot0[1];  // Number of nodes in T2 with odd depth from root 0

        // Find the maximum number of nodes in Tree 2 that can be at an odd distance
        // from any chosen connection point 'j' in Tree 2.
        // This is simply the larger of the two partition sizes in Tree 2.
        int maxOddDistNodesT2 = Math.max(evenPartitionSizeT2, oddPartitionSizeT2);

        // Compute Final Answer
        int[] answer = new int[n];
        for (int i = 0; i < n; i++) {
            int nodesEvenDistFromIinT1; // This is 'even[i]' from Hint 1
            
            // If node 'i' is in the 'even depth' partition of Tree 1 (relative to root 0),
            // then nodes at even distance from 'i' are all nodes in that 'even depth' partition.
            if (nodeParitiesT1[i] == 0) { 
                nodesEvenDistFromIinT1 = evenPartitionSizeT1;
            } 
            // If node 'i' is in the 'odd depth' partition of Tree 1 (relative to root 0),
            // then nodes at even distance from 'i' are all nodes in that 'odd depth' partition.
            else { 
                nodesEvenDistFromIinT1 = oddPartitionSizeT1;
            }
            
            // Total target nodes for 'i' = (nodes in T1 even dist from i) + (max nodes in T2 odd dist from j)
            answer[i] = nodesEvenDistFromIinT1 + maxOddDistNodesT2;
        }

        return answer;
    }
}
