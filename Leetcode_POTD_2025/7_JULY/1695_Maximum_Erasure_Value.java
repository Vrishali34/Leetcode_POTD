import java.util.HashSet;
import java.util.Set;

class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        Set<Integer> celestial_seen = new HashSet<>();
        int max_lumina = 0;
        int current_nebula_sum = 0;
        int voyager_left = 0;

        for (int voyager_right = 0; voyager_right < nums.length; ++voyager_right) {
            while (celestial_seen.contains(nums[voyager_right])) {
                current_nebula_sum -= nums[voyager_left];
                celestial_seen.remove(nums[voyager_left]);
                voyager_left++;
            }
            celestial_seen.add(nums[voyager_right]);
            current_nebula_sum += nums[voyager_right];
            max_lumina = Math.max(max_lumina, current_nebula_sum);
        }
        return max_lumina;
    }
}
