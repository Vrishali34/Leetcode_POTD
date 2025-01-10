class Solution {
    public List<String> wordSubsets(String[] w1, String[] w2) {
        int[] g = new int[26];
        for (String z : w2) {
            int[] c = map(z);
            for (int i = 0; i < 26; i++) g[i] = Math.max(g[i], c[i]);
        }
        List<String> out = new ArrayList<>();
        for (String q : w1) {
            int[] c = map(q);
            boolean ok = true;
            for (int i = 0; i < 26; i++) if (g[i] > c[i]) ok = false;
            if (ok) out.add(q);
        }
        return out;
    }
    private int[] map(String s) {
        int[] f = new int[26];
        for (char x : s.toCharArray()) f[x - 'a']++;
        return f;
    }
}
