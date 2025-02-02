class Solution {
    public boolean check(int[] nums) {
        final int len = nums.length;
        int count = 0;
        for (int i = 0; i < len; ++i) if (nums[i] > nums[(i + 1) % len] && ++count > 1) return false;
        return true;
    }
}
