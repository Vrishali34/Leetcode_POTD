class Solution {
    public int maximumLength(String t) {
        int q = t.length(), a = 1, b = q;
        if (!fn(t, q, a)) return -1;
        while (a + 1 < b) {
            int m = (a + b) / 2;
            if (fn(t, q, m)) a = m;
            else b = m;
        }
        return a;
    }

    private boolean fn(String t, int q, int v) {
        int[] c = new int[26];
        int k = 0;
        for (int i = 0; i < q; i++) {
            while (t.charAt(k) != t.charAt(i)) k++;
            if (i - k + 1 >= v) c[t.charAt(i) - 'a']++;
            if (c[t.charAt(i) - 'a'] > 2) return true;
        }
        return false;
    }
}
