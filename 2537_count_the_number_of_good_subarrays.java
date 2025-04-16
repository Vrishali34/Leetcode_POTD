class Solution {
    public long countGood(int[] x, int y) {
        Map<Integer, Integer> m = new HashMap<>();
        long r = 0, c = 0;
        for (int i = 0, j = 0; j < x.length; ++j) {
            c += m.getOrDefault(x[j], 0);
            m.put(x[j], m.getOrDefault(x[j], 0) + 1);
            while (c >= y) {
                m.put(x[i], m.get(x[i]) - 1);
                c -= m.get(x[i++]);
            }
            r += i;
        }
        return r;
    }
}
