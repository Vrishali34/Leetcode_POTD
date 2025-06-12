class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int maxDiff = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            maxDiff = Math.max(maxDiff, Math.abs(nums[i] - nums[i + 1]));
        }
        return Math.max(maxDiff, Math.abs(nums[nums.length - 1] - nums[0]));
    }
}
