class Solution {
    public int countPairs(int[] q, int p) {
        int c = 0;
        for (int u = 0; u < q.length - 1; u++)
            for (int v = u + 1; v < q.length; v++)
                c += (q[u] == q[v] && u * v % p == 0) ? 1 : 0;
        return c;
    }
}
