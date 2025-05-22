class Solution {
    public int maxRemoval(int[] a, int[][] b) {
        int n = a.length, m = b.length, i = 0, x = 0, res = 0;
        int[] d = new int[n + 2];
        Arrays.sort(b, Comparator.comparingInt(o -> o[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int k = 0; k < n; k++) {
            while (i < m && b[i][0] <= k) pq.offer(b[i++][1]);
            while (x < a[k]) {
                if (pq.isEmpty() || pq.peek() < k) return -1;
                int r = pq.poll();
                d[k]++;
                d[r + 1]--;
                x++;
                res++;
            }
            x += d[k + 1];
        }
        return m - res;
    }
}
