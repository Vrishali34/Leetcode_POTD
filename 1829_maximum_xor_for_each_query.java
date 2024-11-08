class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int mask = (1 << maximumBit) - 1, acc = 0, len = nums.length;
        int[] res = new int[len];
        for (int n : nums) acc ^= n;
        for (int i = 0; i < len; i++) {
            res[i] = acc ^ mask;
            acc ^= nums[len - 1 - i];
        }
        return res;
    }
}
