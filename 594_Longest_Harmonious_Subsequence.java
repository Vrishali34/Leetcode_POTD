import java.util.HashMap;
import java.util.Map;

class Solution {
    public int findLHS(int[] nums) {
        // Use a HashMap to store the frequency of each number
        Map<Integer, Integer> counts = new HashMap<>();
        for (int num : nums) {
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }

        int maxLength = 0;
        // Iterate through the unique numbers in the map
        for (int numVal : counts.keySet()) {
            // Check if numVal + 1 exists in the map.
            // If it does, we've found a potential harmonious pair.
            if (counts.containsKey(numVal + 1)) {
                // Calculate the combined length of the current number and its successor
                int currentLength = counts.get(numVal) + counts.get(numVal + 1);
                // Update maxLength if the current harmonious subsequence is longer
                maxLength = Math.max(maxLength, currentLength);
            }
        }
        return maxLength;
    }
}
