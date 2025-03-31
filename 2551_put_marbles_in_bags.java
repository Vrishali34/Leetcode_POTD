class Solution {
    public long putMarbles(int[] a, int k) {
        List<Integer> x = new ArrayList<>();
        for (int i = 0; i < a.length - 1; i++) x.add(a[i] + a[i + 1]);
        Collections.sort(x);
        long hi = 0, lo = 0;
        for (int i = 0; i < k - 1; i++) {
            lo += x.get(i);
            hi += x.get(x.size() - 1 - i);
        }
        return hi - lo;
    }
}
