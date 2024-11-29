class Solution {
    public int minimumTime(int[][] x) {
        int k = 1024, v[] = {-1, 0, 1, 0, -1}, l = x.length, y = x[0].length;
        if (x[0][1] > 1 && x[1][0] > 1) return -1;
        PriorityQueue<int[]> pq = new PriorityQueue<>((u, b) -> u[0] - b[0]);
        pq.add(new int[]{0, 0});
        x[0][0] = -1;
        while (!pq.isEmpty()) {
            var w = pq.poll();
            int a = w[1] / k, b = w[1] % k, c = w[0];
            if (a == l - 1 && b == y - 1) return c;
            for (int i = 0; i < 4; ++i) {
                int na = a + v[i], nb = b + v[i + 1];
                if (na >= 0 && na < l && nb >= 0 && nb < y && x[na][nb] != -1) {
                    int nc = c + 1;
                    if (nc < x[na][nb]) nc = (x[na][nb] - nc) % 2 == 1 ? x[na][nb] + 1 : x[na][nb];
                    pq.add(new int[]{nc, na * k + nb});
                    x[na][nb] = -1;
                }
            }
        }
        return -1000;
    }
}
