import java.util.*;

class Solution {
    Map<Integer, List<Integer>> g = new HashMap<>();
    Map<Integer, Integer> bobMap = new HashMap<>();
    int maxProfit = Integer.MIN_VALUE;

    boolean dfsBob(int node, int time, boolean[] visited) {
        visited[node] = true;
        bobMap.put(node, time);
        if (node == 0) return true;
        for (int neighbor : g.get(node)) {
            if (!visited[neighbor] && dfsBob(neighbor, time + 1, visited)) {
                return true;
            }
        }
        bobMap.remove(node);
        return false;
    }

    void dfsAlice(int node, int time, int profit, boolean[] visited, int[] amount) {
        visited[node] = true;
        if (!bobMap.containsKey(node) || time < bobMap.get(node)) {
            profit += amount[node];
        } else if (time == bobMap.get(node)) {
            profit += amount[node] / 2;
        }
        if (g.get(node).size() == 1 && node != 0) {
            maxProfit = Math.max(maxProfit, profit);
        }
        for (int neighbor : g.get(node)) {
            if (!visited[neighbor]) {
                dfsAlice(neighbor, time + 1, profit, visited, amount);
            }
        }
    }

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        for (int[] e : edges) {
            g.computeIfAbsent(e[0], k -> new ArrayList<>()).add(e[1]);
            g.computeIfAbsent(e[1], k -> new ArrayList<>()).add(e[0]);
        }
        boolean[] visited = new boolean[amount.length];
        dfsBob(bob, 0, visited);
        Arrays.fill(visited, false);
        dfsAlice(0, 0, 0, visited, amount);
        return maxProfit;
    }
}
