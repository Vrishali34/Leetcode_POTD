class Solution {
    public int numWays(String[] words, String target) {
        int n = words[0].length(), m = target.length(), MOD = 1000000007;
        int[][] freq = new int[n][26];
        for (String word : words)
            for (int i = 0; i < n; i++)
                freq[i][word.charAt(i) - 'a']++;
        Integer[][] dp = new Integer[n + 1][m + 1];
        return helper(freq, target, 0, 0, dp, MOD);
    }

    private int helper(int[][] freq, String target, int idx, int pos, Integer[][] dp, int MOD) {
        if (pos == target.length()) return 1;
        if (idx == freq.length) return 0;
        if (dp[idx][pos] != null) return dp[idx][pos];
        int skip = helper(freq, target, idx + 1, pos, dp, MOD);
        int use = freq[idx][target.charAt(pos) - 'a'] > 0 
                ? (int)((long)freq[idx][target.charAt(pos) - 'a'] * helper(freq, target, idx + 1, pos + 1, dp, MOD) % MOD) 
                : 0;
        return dp[idx][pos] = (skip + use) % MOD;
    }
}
