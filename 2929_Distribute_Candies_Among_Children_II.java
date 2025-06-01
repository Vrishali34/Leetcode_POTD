class Solution {
    public long distributeCandies(int n, int limit) {
        long ans = 0;
        for (int i = 0; i <= limit; ++i) {
            int rem = n - i;
            if (rem < 0) break;
            int min_val = Math.max(0, rem - limit);
            int max_val = Math.min(limit, rem);
            
            if (max_val >= min_val) {
                ans += (max_val - min_val + 1);
            }
        }
        return ans;
    }
}
