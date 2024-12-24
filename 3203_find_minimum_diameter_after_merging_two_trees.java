class Solution {
    private int calculateDiameter(int[][] edges) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        int[] degree = new int[edges.length + 1];
        for (int[] edge : edges) {
            graph.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            graph.computeIfAbsent(edge[1], k -> new ArrayList<>()).add(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < degree.length; i++) {
            if (degree[i] == 1) queue.add(i);
        }
        int nodes = edges.length + 1, depth = 0;
        while (nodes > 2) {
            int size = queue.size();
            nodes -= size;
            depth++;
            while (size-- > 0) {
                int node = queue.poll();
                for (int neighbor : graph.get(node)) {
                    if (--degree[neighbor] == 1) queue.add(neighbor);
                }
            }
        }
        return nodes == 2 ? 2 * depth + 1 : 2 * depth;
    }

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        int d1 = calculateDiameter(edges1);
        int d2 = calculateDiameter(edges2);
        return Math.max(d1, Math.max(d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1));
    }
}
