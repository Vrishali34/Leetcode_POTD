class Solution {
    public int minDominoRotations(int[] p, int[] q) {
        for (int d : new int[]{p[0], q[0]}) {
            int u = 0, v = 0;
            boolean ok = true;
            for (int i = 0; i < p.length; i++) {
                if (p[i] != d && q[i] != d) {
                    ok = false;
                    break;
                }
                if (p[i] != d) u++;
                if (q[i] != d) v++;
            }
            if (ok) return Math.min(u, v);
        }
        return -1;
    }
}
