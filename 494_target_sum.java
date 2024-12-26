class Solution {
    private int xoo(int idx, int[] arr, int tar, int len) {
        return idx == len ? (tar == 0 ? 1 : 0) : xoo(idx + 1, arr, tar - arr[idx], len) + xoo(idx + 1, arr, tar + arr[idx], len);
    }
    public int findTargetSumWays(int[] nums, int target) {
        return xoo(0, nums, target, nums.length);
    }
}
