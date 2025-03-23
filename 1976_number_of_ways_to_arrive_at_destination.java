class Solution {
    public int countPaths(int z, int[][] q) {
        List<int[]>[] r = new List[z];
        for (int i = 0; i < z; i++) r[i] = new ArrayList<>();
        for (int[] a : q) {
            r[a[0]].add(new int[]{a[1], a[2]});
            r[a[1]].add(new int[]{a[0], a[2]});
        }
        long[] d = new long[z], c = new long[z];
        Arrays.fill(d, Long.MAX_VALUE); d[0] = 0; c[0] = 1;
        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        pq.add(new long[]{0, 0});
        while (!pq.isEmpty()) {
            long[] u = pq.poll(); int v = (int) u[1];
            if (u[0] > d[v]) continue;
            for (int[] e : r[v]) {
                long t = u[0] + e[1];
                if (t < d[e[0]]) {
                    d[e[0]] = t; c[e[0]] = c[v];
                    pq.add(new long[]{t, e[0]});
                } else if (t == d[e[0]]) {
                    c[e[0]] = (c[e[0]] + c[v]) % 1_000_000_007;
                }
            }
        }
        return (int) c[z - 1];
    }
}
