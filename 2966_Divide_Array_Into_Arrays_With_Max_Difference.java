import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        List<int[]> collectionOfTriplets = new ArrayList<>();

        for (int i = 0; i < nums.length; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return new int[0][0]; // Return empty array if condition not met
            }
            collectionOfTriplets.add(new int[]{nums[i], nums[i + 1], nums[i + 2]});
        }

        // Convert List<int[]> to int[][]
        return collectionOfTriplets.toArray(new int[0][0]);
    }
}
