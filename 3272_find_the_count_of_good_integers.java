class Solution {
    public long countGoodIntegers(int n, int k) {
        int m = (n + 1) / 2, lo = (int)Math.pow(10, m - 1), hi = (int)Math.pow(10, m);
        Set<String> seen = new HashSet<>();
        long res = 0;
        for (int i = lo; i < hi; ++i) {
            String a = i + "", b = new StringBuilder(a).reverse().toString();
            String p = a + b.substring(n % 2);
            if (Long.parseLong(p) % k != 0) continue;
            char[] arr = p.toCharArray();
            Arrays.sort(arr);
            String sig = new String(arr);
            if (!seen.add(sig)) continue;
            int[] f = new int[10];
            for (char c : p.toCharArray()) f[c - '0']++;
            long x = n - f[0], y = 1;
            for (int j = 2; j <= n - 1; ++j) x *= j;
            for (int v : f) for (int j = 2; j <= v; ++j) y *= j;
            res += x / y;
        }
        return res;
    }
}
