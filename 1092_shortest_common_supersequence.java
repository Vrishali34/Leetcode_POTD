class Solution {
    public String shortestCommonSupersequence(String s, String t) {
        int a = s.length(), b = t.length();
        int[][] p = new int[a + 1][b + 1];

        // Step 1: Compute the DP table for SCS length
        for (int i = 0; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                if (i == 0 || j == 0) {
                    p[i][j] = i + j;
                } else if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    p[i][j] = 1 + p[i - 1][j - 1];
                } else {
                    p[i][j] = 1 + Math.min(p[i - 1][j], p[i][j - 1]);
                }
            }
        }

        // Step 2: Construct the shortest supersequence using DP table
        StringBuilder sb = new StringBuilder();
        int i = a, j = b;

        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && s.charAt(i - 1) == t.charAt(j - 1)) {
                sb.append(s.charAt(i - 1));
                i--;
                j--;
            } else if (i > 0 && (j == 0 || p[i - 1][j] < p[i][j - 1])) {
                sb.append(s.charAt(i - 1));
                i--;
            } else {
                sb.append(t.charAt(j - 1));
                j--;
            }
        }

        return sb.reverse().toString();
    }
}
