class Solution {
    public int maximumInvitations(int[] F) {
        int n = F.length, z = 0, t = 0;
        int[] x = new int[n], y = new int[n];
        boolean[] v = new boolean[n];
        for (int f : F) x[f]++;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) if (x[i] == 0) q.add(i);
        while (!q.isEmpty()) {
            int a = q.poll();
            v[a] = true;
            int b = F[a];
            y[b] = y[a] + 1;
            if (--x[b] == 0) q.add(b);
        }
        for (int i = 0; i < n; i++) if (!v[i]) {
            int c = 0, j = i;
            while (!v[j]) {
                v[j] = true;
                j = F[j];
                c++;
            }
            if (c == 2) t += 2 + y[i] + y[F[i]];
            else z = Math.max(z, c);
        }
        return Math.max(z, t);
    }
}
