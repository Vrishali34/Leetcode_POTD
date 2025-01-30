import java.util.*;

class Solution {
    public int magnificentSets(int n, int[][] edges) {
        List<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) g[i] = new ArrayList<>();
        for (int[] e : edges) {
            g[e[0] - 1].add(e[1] - 1);
            g[e[1] - 1].add(e[0] - 1);
        }
        
        int[] color = new int[n];
        Arrays.fill(color, -1);
        int[] parent = new int[n], rank = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        
        for (int i = 0; i < n; i++) {
            if (color[i] == -1 && !isBipartite(g, i, color, parent, rank)) return -1;
        }
        
        Map<Integer, List<Integer>> groups = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int root = find(parent, i);
            groups.putIfAbsent(root, new ArrayList<>());
            groups.get(root).add(i);
        }
        
        int res = 0;
        for (List<Integer> group : groups.values()) {
            int maxLevel = 0;
            for (int node : group) maxLevel = Math.max(maxLevel, bfs(g, node, n));
            res += maxLevel;
        }
        return res;
    }

    boolean isBipartite(List<Integer>[] g, int src, int[] color, int[] parent, int[] rank) {
        Queue<Integer> q = new LinkedList<>();
        q.add(src);
        color[src] = 0;
        
        while (!q.isEmpty()) {
            int node = q.poll();
            for (int nei : g[node]) {
                if (color[nei] == -1) {
                    color[nei] = 1 - color[node];
                    union(parent, rank, node, nei);
                    q.add(nei);
                } else if (color[nei] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

    int bfs(List<Integer>[] g, int src, int n) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[n];
        q.add(src);
        visited[src] = true;
        int level = 0;
        
        while (!q.isEmpty()) {
            for (int size = q.size(); size > 0; size--) {
                int node = q.poll();
                for (int nei : g[node]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.add(nei);
                    }
                }
            }
            level++;
        }
        return level;
    }

    int find(int[] parent, int x) {
        if (parent[x] != x) parent[x] = find(parent, parent[x]);
        return parent[x];
    }

    void union(int[] parent, int[] rank, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
            else { parent[rootY] = rootX; rank[rootX]++; }
        }
    }
}
