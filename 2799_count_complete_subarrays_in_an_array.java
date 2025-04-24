class Solution {
    public int countCompleteSubarrays(int[] z) {
        int u = (int) Arrays.stream(z).distinct().count(), c = 0;
        for (int i = 0; i < z.length; ++i) {
            Set<Integer> s = new HashSet<>();
            for (int j = i; j < z.length; ++j) {
                s.add(z[j]);
                if (s.size() == u) c++;
                if (s.size() > u) break;
            }
        }
        return c;
    }
}
