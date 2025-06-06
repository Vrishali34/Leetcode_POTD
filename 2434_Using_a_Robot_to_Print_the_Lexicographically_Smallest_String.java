import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public String robotWithString(String s) {
        // 1. Calculate character frequencies in the input string 's'
        int[] freq = new int[26];
        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        StringBuilder paper = new StringBuilder(); // Stores the final lexicographically smallest string
        Deque<Character> robotT = new ArrayDeque<>(); // Simulates the robot's string 't' (a stack)

        // 2. Process each character from the input string 's'
        for (char curSChar : s.toCharArray()) {
            // Operation 1: Move the character from 's' to 't'
            robotT.push(curSChar); // Add to the top of the stack
            freq[curSChar - 'a']--; // Decrement its frequency

            // 3. Determine the smallest character remaining in 's' (not yet moved to 't')
            char smallestRemainingChar = 'z' + 1; // Initialize with a character greater than 'z'
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    smallestRemainingChar = (char) ('a' + i);
                    break; // Found the smallest, no need to check further
                }
            }

            // 4. Operation 2: Try to move characters from 't' to 'paper'
            // We can move if the top of 't' is less than or equal to the smallest remaining character in 's'
            while (!robotT.isEmpty() && robotT.peek() <= smallestRemainingChar) {
                paper.append(robotT.pop()); // Move from 't' to 'paper'
            }
        }

        // 5. After processing all characters from 's', move any remaining characters from 't' to 'paper'
        while (!robotT.isEmpty()) {
            paper.append(robotT.pop());
        }

        return paper.toString(); // Return the final string
    }
}
