import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxDifference(String s) {
        Map<Character, Integer> charFrequencies = new HashMap<>();
        for (char c : s.toCharArray()) {
            charFrequencies.put(c, charFrequencies.getOrDefault(c, 0) + 1);
        }

        int maxOddFrequency = 0;
        int minEvenFrequency = Integer.MAX_VALUE; 

        for (int frequency : charFrequencies.values()) {
            if (frequency % 2 != 0) { // Odd frequency
                maxOddFrequency = Math.max(maxOddFrequency, frequency);
            } else { // Even frequency
                minEvenFrequency = Math.min(minEvenFrequency, frequency);
            }
        }
        return maxOddFrequency - minEvenFrequency;
    }
}
