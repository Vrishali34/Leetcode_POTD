import java.util.PriorityQueue;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    /**
     * Clears stars from the string according to the given rules:
     * When a '*' is encountered, remove the leftmost '*' and the smallest non-'*' character to its left.
     * If there are multiple smallest characters, any can be deleted.
     * The goal is to return the lexicographically smallest resulting string.
     *
     * @param s The input string, containing lowercase English letters and '*' characters.
     * @return The lexicographically smallest string after all '*' characters and their corresponding
     * smallest characters to the left have been removed.
     */
    public String clearStars(String s) {
        // A min-priority queue to efficiently retrieve the smallest character seen so far.
        // It stores characters that are candidates for removal when a '*' is encountered.
        PriorityQueue<Character> charMinHeap = new PriorityQueue<>();

        // An array of lists to store the indices of each character.
        // For example, charIndices[0] will store all indices where 'a' appears,
        // charIndices[1] for 'b', and so on.
        // This allows us to quickly find the last (most recent) occurrence of a character.
        @SuppressWarnings("unchecked") // Suppress unchecked cast warning for array of generic lists
        List<Integer>[] charIndices = new ArrayList[26];
        for (int i = 0; i < 26; i++) {
            charIndices[i] = new ArrayList<>();
        }

        // A boolean array to mark characters that should be kept in the final string.
        // Initially, all characters are assumed to be kept.
        boolean[] shouldKeep = new boolean[s.length()];
        Arrays.fill(shouldKeep, true); // Set all to true

        // Iterate through the input string character by character.
        for (int i = 0; i < s.length(); ++i) {
            char currentChar = s.charAt(i);

            if (currentChar == '*') {
                // If the current character is a star, we need to perform a removal operation.
                // 1. Get the smallest character currently in the heap.
                char smallestChar = charMinHeap.poll();

                // 2. Find the original index of this smallest character.
                // Since we want the *most recent* occurrence to the left, we take the last index
                // added to its corresponding list in `charIndices`.
                int targetIndex = charIndices[smallestChar - 'a'].remove(charIndices[smallestChar - 'a'].size() - 1);

                // 3. Mark both the current '*' and the found character for deletion.
                shouldKeep[i] = false; // Mark the '*' itself to be removed
                shouldKeep[targetIndex] = false; // Mark the smallest character to be removed

            } else {
                // If the current character is a letter:
                // 1. Add it to the min-priority queue.
                charMinHeap.offer(currentChar);
                // 2. Record its original index in the corresponding list.
                charIndices[currentChar - 'a'].add(i);
            }
        }

        // After processing the entire string, build the final result string.
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < s.length(); ++i) {
            // Append characters that were marked to be kept.
            if (shouldKeep[i]) {
                result.append(s.charAt(i));
            }
        }

        return result.toString(); // Convert StringBuilder to String and return
    }
}
