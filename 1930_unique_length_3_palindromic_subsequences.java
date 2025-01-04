class Solution {
    public int countPalindromicSubsequence(String x) {
        int n = x.length(), res = 0;
        int[] start = new int[26], end = new int[26];
        Arrays.fill(start, -1);
        Arrays.fill(end, n);
        for (int i = 0; i < n; i++) {
            if (start[x.charAt(i) - 'a'] == -1) start[x.charAt(i) - 'a'] = i;
            end[x.charAt(i) - 'a'] = i;
        }
        for (int c = 0; c < 26; c++) {
            if (start[c] != -1 && end[c] != n) {
                Set<Character> chars = new HashSet<>();
                for (int j = start[c] + 1; j < end[c]; j++) chars.add(x.charAt(j));
                res += chars.size();
            }
        }
        return res;
    }
}
