import java.util.Collections;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

class Solution {
    public int minimumDeletions(String word, int k) {
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char c : word.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        List<Integer> uniqueFreqs = new ArrayList<>(freqMap.values());
        Collections.sort(uniqueFreqs);

        int minDeletions = Integer.MAX_VALUE;

        for (int lowFreqTarget : uniqueFreqs) {
            int currentDeletions = 0;
            for (int charFreq : freqMap.values()) {
                if (charFreq < lowFreqTarget) {
                    currentDeletions += charFreq;
                } else if (charFreq > lowFreqTarget + k) {
                    currentDeletions += charFreq - (lowFreqTarget + k);
                }
            }
            minDeletions = Math.min(minDeletions, currentDeletions);
        }
        
        return minDeletions;
    }
}
