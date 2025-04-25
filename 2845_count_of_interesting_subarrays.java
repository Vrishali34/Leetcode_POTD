class Solution {
    public long countInterestingSubarrays(List<Integer> a, int b, int c) {
        Map<Integer, Long> d = new HashMap<>();
        d.put(0, 1L);
        long e = 0, f = 0;
        for (int g : a) {
            f += (g % b == c) ? 1 : 0;
            e += d.getOrDefault((int)((f - c + b) % b), 0L);
            d.put((int)(f % b), d.getOrDefault((int)(f % b), 0L) + 1);
        }
        return e;
    }
}
