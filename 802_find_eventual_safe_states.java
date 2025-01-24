class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        boolean[] visited = new boolean[n];
        boolean[] onPath = new boolean[n];
        boolean[] safe = new boolean[n];

        for (int i = 0; i < n; i++) {
            dfs(i, graph, visited, onPath, safe);
        }

        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (safe[i]) result.add(i);
        }

        return result;
    }

    private boolean dfs(int node, int[][] graph, boolean[] visited, boolean[] onPath, boolean[] safe) {
        if (visited[node]) return safe[node];
        visited[node] = true;
        onPath[node] = true;

        for (int neighbor : graph[node]) {
            if (onPath[neighbor] || !dfs(neighbor, graph, visited, onPath, safe)) {
                safe[node] = false;
                return safe[node];
            }
        }

        onPath[node] = false;
        safe[node] = true;
        return safe[node];
    }
}
