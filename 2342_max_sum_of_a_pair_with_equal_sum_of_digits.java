class Solution {
    int zap(int n) {
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

    public int maximumSum(int[] arr) {
        int res = -1, z[] = new int[82];
        for (int x : arr) {
            int d = zap(x);
            if (z[d] > 0) res = Math.max(res, z[d] + x);
            z[d] = Math.max(z[d], x);
        }
        return res;
    }
}
