class Solution {
    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        int mod = 1_000_000_007, size = 26;
        long[][] trans = new long[size][size], res = new long[size][size];
        for (int i = 0; i < size; i++) res[i][i] = 1;
        for (int i = 0; i < size; i++)
            for (int j = 1; j <= nums.get(i); j++)
                trans[i][(i + j) % size]++;
        while (t > 0) {
            if ((t & 1) == 1) res = multiply(res, trans, mod);
            trans = multiply(trans, trans, mod);
            t >>= 1;
        }
        long[] count = new long[size];
        for (char c : s.toCharArray()) count[c - 'a']++;
        long total = 0;
        for (int i = 0; i < size; i++) {
            long sum = 0;
            for (int j = 0; j < size; j++) sum = (sum + res[i][j]) % mod;
            total = (total + count[i] * sum) % mod;
        }
        return (int) total;
    }

    private long[][] multiply(long[][] a, long[][] b, int mod) {
        int n = a.length;
        long[][] result = new long[n][n];
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++)
                for (int j = 0; j < n; j++)
                    result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % mod;
        return result;
    }
}
