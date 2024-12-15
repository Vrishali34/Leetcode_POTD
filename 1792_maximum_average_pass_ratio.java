class Solution {
    public double maxAverageRatio(int[][] b, int n) {
        PriorityQueue<int[]> q = new PriorityQueue<>((a, c) -> Double.compare(
                (c[0] + 1.0) / (c[1] + 1.0) - c[0] * 1.0 / c[1],
                (a[0] + 1.0) / (a[1] + 1.0) - a[0] * 1.0 / a[1]));
        double w = 0;
        for (int[] k : b) {
            q.add(k);
            w += k[0] * 1.0 / k[1];
        }
        while (n-- > 0) {
            int[] h = q.poll();
            w += (h[0] + 1.0) / (h[1] + 1.0) - h[0] * 1.0 / h[1];
            h[0]++;
            h[1]++;
            q.add(h);
        }
        return w / b.length;
    }
}
