import java.util.*;

class Solution {
    public int maximumScore(int[] a, int k) {
        int m = (int)1e9 + 7, n = a.length;
        int[] f = new int[100002], g = new int[n], l = new int[n], r = new int[n];
        Arrays.setAll(f, i -> i);
        
        for (int i = 2; i * i < f.length; ++i) {
            for (int j = i * i; j < f.length; j += i) {
                f[j] = Math.min(f[j], i);
            }
        }

        for (int i = 0; i < n; ++i) {
            Set<Integer> s = new HashSet<>();
            for (int x = a[i]; x > 1; x /= f[x]) {
                s.add(f[x]);
            }
            g[i] = s.size();
        }

        Arrays.fill(l, -1);
        Arrays.fill(r, n);
        Stack<Integer> z = new Stack<>();
        
        for (int i = n - 1; i >= 0; --i) {
            while (!z.isEmpty() && g[z.peek()] <= g[i]) {
                l[z.pop()] = i;
            }
            z.push(i);
        }

        z.clear();
        for (int i = 0; i < n; ++i) {
            while (!z.isEmpty() && g[z.peek()] < g[i]) {
                r[z.pop()] = i;
            }
            z.push(i);
        }

        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; ++i) idx[i] = i;
        
        Arrays.sort(idx, (i, j) -> 
            a[i] != a[j] ? Integer.compare(a[j], a[i]) : Integer.compare(i, j)
        );

        long res = 1;
        for (int i : idx) {
            long cnt = (long)(i - l[i]) * (r[i] - i);
            cnt = Math.min((long)k, cnt); 
            k -= cnt;
            res = res * modPow(a[i], cnt, m) % m;
            if (k == 0) break;
        }

        return (int)res;
    }

    // Efficient Modular Exponentiation
    private long modPow(long base, long exp, int mod) {
        long res = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) res = res * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return res;
    }
}
