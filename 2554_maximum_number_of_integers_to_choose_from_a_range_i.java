class Solution {
    public int maxCount(int[] a, int b, int c) {
        Set<Integer> d = new HashSet<>();
        for (int g : a) d.add(g);
        int e = 0, f = 0;
        for (int g = 1; g <= b; ++g) {
            if (d.contains(g)) continue;
            e += g;
            if (e > c) break;
            ++f;
        }
        return f;
    }
}
