import java.util.Arrays;

class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int num_subsequences = 0;
        int i = 0;
        while (i < nums.length) {
            num_subsequences++;
            int current_min = nums[i];
            while (i < nums.length && nums[i] - current_min <= k) {
                i++;
            }
        }
        return num_subsequences;
    }
}
