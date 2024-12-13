import java.util.Arrays;

class Solution {
    public long findScore(int[] nums) {
        long total = 0;
        int n = nums.length;
        // Create an array of pairs (value, index)
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }
        
        // Sort the array by the first element (value)
        Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));
        
        boolean[] used = new boolean[n];
        
        for (int i = 0; i < n; i++) {
            int val = arr[i][0];
            int index = arr[i][1];
            
            if (used[index]) continue;
            
            total += val;
            
            if (index > 0) used[index - 1] = true;
            if (index < n - 1) used[index + 1] = true;
            used[index] = true;
        }
        
        return total;
    }
}
