class Solution {
    public List<Integer> partitionLabels(String s) {
        int[] f = new int[128];
        for (int i = 0; i < s.length(); i++) f[s.charAt(i)] = i;
        List<Integer> r = new ArrayList<>();
        for (int i = 0, e = 0, b = 0; i < s.length(); i++) {
            e = Math.max(e, f[s.charAt(i)]);
            if (i == e) {
                r.add(i - b + 1);
                b = i + 1;
            }
        }
        return r;
    }
}
