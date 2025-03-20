class Solution {
    class X {
        int[] p, r, w;
        X(int n) {
            p = new int[n];
            r = new int[n];
            w = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
                w[i] = (1 << 17) - 1;
            }
        }
        int f(int a) {
            return p[a] == a ? a : (p[a] = f(p[a]));
        }
        void u(int a, int b, int c) {
            int x = f(a), y = f(b), v = w[x] & w[y] & c;
            w[x] = v;
            w[y] = v;
            if (x != y) {
                if (r[x] < r[y]) p[x] = y;
                else if (r[x] > r[y]) p[y] = x;
                else { p[x] = y; r[y]++; }
            }
        }
        int q(int a, int b) {
            return f(a) == f(b) ? w[f(a)] : -1;
        }
    }
    public int[] minimumCost(int n, int[][] e, int[][] q) {
        X x = new X(n);
        for (var v : e) x.u(v[0], v[1], v[2]);
        int[] a = new int[q.length];
        for (int i = 0; i < q.length; i++) a[i] = x.q(q[i][0], q[i][1]);
        return a;
    }
}
