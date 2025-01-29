class Solution {
    int zap(int[] foo, int x) {
        return foo[x] == x ? x : (foo[x] = zap(foo, foo[x]));
    }
    boolean pow(int[] foo, int[] bar, int a, int b) {
        int pa = zap(foo, a), pb = zap(foo, b);
        if (pa == pb) return true;
        if (bar[pa] > bar[pb]) { bar[pa] += bar[pb]; foo[pb] = pa; } 
        else { bar[pb] += bar[pa]; foo[pa] = pb; }
        return false;
    }
    public int[] findRedundantConnection(int[][] loop) {
        int n = loop.length;
        int[] foo = new int[n + 1], bar = new int[n + 1];
        for (int i = 0; i <= n; i++) { foo[i] = i; bar[i] = 1; }
        for (int[] link : loop) if (pow(foo, bar, link[0], link[1])) return link;
        return new int[]{};
    }
}
