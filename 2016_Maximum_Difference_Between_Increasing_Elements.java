class Solution {
    public int maximumDifference(int[] nums) {
        int max_diff = -1;
        int min_so_far = nums[0];

        for (int k = 1; k < nums.length; k++) {
            if (nums[k] > min_so_far) {
                max_diff = Math.max(max_diff, nums[k] - min_so_far);
            }
            min_so_far = Math.min(min_so_far, nums[k]);
        }
        return max_diff;
    }
}
