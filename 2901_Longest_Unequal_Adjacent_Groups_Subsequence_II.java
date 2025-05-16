import java.util.*;

class Solution {
    public List<String> getWordsInLongestSubsequence(String[] words, int[] groups) {
        List<String> result = new ArrayList<>();
        int prevGroup = -1; // no group selected initially
        
        for (int i = 0; i < words.length; i++) {
            if (groups[i] != prevGroup) {
                result.add(words[i]);
                prevGroup = groups[i]; // update last selected group
            }
        }
        return result;
    }
}
