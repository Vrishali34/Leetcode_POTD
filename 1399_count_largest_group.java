class Solution {
    public int countLargestGroup(int n) {
        int[] a = new int[37];
        int max = 0, res = 0;
        for (int i = 1; i <= n; i++) {
            int s = 0, x = i;
            while (x > 0) { s += x % 10; x /= 10; }
            max = Math.max(max, ++a[s]);
        }
        for (int v : a) if (v == max) res++;
        return res;
    }
}
