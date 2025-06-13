import java.util.Arrays;

class Solution {
    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int n = nums.length;
        int low = 0;
        int high = nums[n - 1] - nums[0];
        int minMaxDiff = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int pairsCount = 0;
            for (int i = 0; i < n - 1; ) {
                if (nums[i+1] - nums[i] <= mid) {
                    pairsCount++;
                    i += 2;
                } else {
                    i++;
                }
            }

            if (pairsCount >= p) {
                minMaxDiff = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return minMaxDiff;
    }
}
