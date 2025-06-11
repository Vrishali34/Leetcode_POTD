class Solution {
    public int maxDifference(String f, int h) {
        int r = Integer.MIN_VALUE, n = f.length();
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                if (i != j) {
                    int x = 0, y = 0, px = 0, py = 0, l = -1;
                    int[] T = new int[4];
                    for (int t = 0; t < 4; t++) T[t] = Integer.MAX_VALUE;
                    for (int z = 0; z < n; ++z) {
                        x += f.charAt(z) == ('0' + i) ? 1 : 0;
                        y += f.charAt(z) == ('0' + j) ? 1 : 0;
                        while (z - l >= h && y - py >= 2) {
                            T[(px & 1) << 1 | (py & 1)] = Math.min(T[(px & 1) << 1 | (py & 1)], px - py);
                            l++;
                            px += f.charAt(l) == ('0' + i) ? 1 : 0;
                            py += f.charAt(l) == ('0' + j) ? 1 : 0;
                        }
                        int p1 = ((x & 1) ^ 1) << 1 | (y & 1);
                        if (T[p1] != Integer.MAX_VALUE)
                            r = Math.max(r, x - y - T[p1]);
                    }
                }
        return r;
    }
}
