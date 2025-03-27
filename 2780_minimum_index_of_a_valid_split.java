class Solution {
    public int minimumIndex(List<Integer> z) {
        Map<Integer, Integer> f = new HashMap<>();
        for (int v : z) f.put(v, f.getOrDefault(v, 0) + 1);
        int d = 0, c = 0, n = z.size();
        for (var e : f.entrySet()) if (e.getValue() * 2 > n) { d = e.getKey(); c = e.getValue(); }
        int x = 0;
        for (int i = 0; i < n - 1; i++) {
            if (z.get(i) == d) x++;
            if (x * 2 > i + 1 && (c - x) * 2 > n - i - 1) return i;
        }
        return -1;
    }
}
