class Solution {
    public int maximumBeauty(int[] nums, int k) {
        int n = nums.length;
        int maxVal = 0;
        
        // Find the maximum value in the array
        for (int i = 0; i < n; i++) {
            maxVal = Math.max(maxVal, nums[i]);
        }
        
        // Create a range array to count the number of elements in the range
        int[] range = new int[maxVal + 10];  // An array for tracking the range
        for (int i = 0; i < n; i++) {
            int left = Math.max(0, nums[i] - k);
            int right = Math.min(maxVal, nums[i] + k) + 1;
            range[left]++;
            if (right < range.length) {
                range[right]--;
            }
        }
        
        // Compute the maximum beauty
        int result = range[0];
        for (int i = 1; i < range.length; i++) {
            range[i] += range[i - 1];
            result = Math.max(result, range[i]);
        }
        
        return result;
    }
}
