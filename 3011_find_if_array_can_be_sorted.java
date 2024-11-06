class Solution {
    public boolean canSortArray(int[] nums) {
        boolean sortFlag = true;
        while (sortFlag) {
            sortFlag = false;
            for (int k = 1; k < nums.length; k++) {
                if (Integer.bitCount(nums[k]) == Integer.bitCount(nums[k - 1]) && nums[k - 1] > nums[k]) {
                    int tmp = nums[k];
                    nums[k] = nums[k - 1];
                    nums[k - 1] = tmp;
                    sortFlag = true;
                }
            }
        }
        return sorted(nums);
    }

    private boolean sorted(int[] nums) {
        for (int k = 1; k < nums.length; k++) {
            if (nums[k - 1] > nums[k]) return false;
        }
        return true;
    }
}
