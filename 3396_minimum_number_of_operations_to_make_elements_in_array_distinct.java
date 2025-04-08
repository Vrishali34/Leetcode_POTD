import java.util.HashSet;

class Solution {
    public int minimumOperations(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        if (set.size() == nums.length) {
            return 0;
        }
        int operations = 0;
        while (nums.length > 3) {
            int[] temp = new int[nums.length - 3];
            System.arraycopy(nums, 3, temp, 0, nums.length - 3);
            nums = temp;
            operations++;
            set.clear();
            for (int num : nums) {
                set.add(num);
            }
            if (set.size() == nums.length) {
                break;
            }
        }
        set.clear();
        for (int num : nums) {
            set.add(num);
        }
        return operations + (set.size() < nums.length ? 1 : 0);
    }
}
