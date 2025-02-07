class Solution {
    public int[] queryResults(int x, int[][] y) {
        int z = y.length;
        int[] w = new int[z];
        Map<Integer, Integer> a = new HashMap<>(), b = new HashMap<>();
        for (int i = 0; i < z; i++) {
            int c = y[i][0], d = y[i][1];
            if (a.containsKey(c)) {
                int e = a.get(c);
                b.put(e, b.get(e) - 1);
                if (b.get(e) == 0) b.remove(e);
            }
            a.put(c, d);
            b.put(d, b.getOrDefault(d, 0) + 1);
            w[i] = b.size();
        }
        return w;
    }
}
