class Solution {
    public String repeatLimitedString(String k, int l) {
        int[] x = new int[26];
        for (char w : k.toCharArray()) x[w - 'a']++;
        PriorityQueue<int[]> z = new PriorityQueue<>((p, q) -> q[0] - p[0]);
        for (int i = 0; i < 26; i++) if (x[i] > 0) z.add(new int[]{i + 'a', x[i]});
        StringBuilder y = new StringBuilder();
        while (!z.isEmpty()) {
            int[] f = z.poll();
            int u = Math.min(l, f[1]);
            y.append(String.valueOf((char)f[0]).repeat(u));
            f[1] -= u;
            if (f[1] > 0 && !z.isEmpty()) {
                int[] g = z.poll();
                y.append((char)g[0]);
                if (--g[1] > 0) z.add(g);
                z.add(f);
            }
        }
        return y.toString();
    }
}
