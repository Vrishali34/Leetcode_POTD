import java.util.*;

class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        if (nums.length == 0) return new ArrayList<>();
        
        Arrays.sort(nums);
        int n = nums.length;
        int[] dp = new int[n];
        int[] prev = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(prev, -1);
        
        int maxIdx = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIdx]) {
                maxIdx = i;
            }
        }
        
        List<Integer> result = new ArrayList<>();
        while (maxIdx >= 0) {
            result.add(nums[maxIdx]);
            maxIdx = prev[maxIdx];
        }
        
        Collections.reverse(result);
        return result;
    }
}
