class Solution {
    public int maxKDivisibleComponents(int n, int[][] edg, int[] val, int k) {
        List<List<Integer>> gr = new ArrayList<>();
        int[] deg = new int[n];
        if (n < 2) return 1;
        for (int i = 0; i < n; i++) gr.add(new ArrayList<>());
        for (int[] e : edg) {
            gr.get(e[0]).add(e[1]);
            gr.get(e[1]).add(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }
        long[] v = new long[n];
        for (int i = 0; i < n; i++) v[i] = (long) val[i]; 
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) if (deg[i] == 1) q.offer(i);
        int cnt = 0;
        while (!q.isEmpty()) {
            int u = q.poll();
            deg[u]--;
            long tmp = 0;  
            if (v[u] % k == 0) cnt++;
            else tmp = v[u];
            for (int nb : gr.get(u)) {
                if (deg[nb] == 0) continue;
                deg[nb]--;
                v[nb] += tmp;
                if (deg[nb] == 1) q.offer(nb);
            }
        }
        return cnt;
    }
}
