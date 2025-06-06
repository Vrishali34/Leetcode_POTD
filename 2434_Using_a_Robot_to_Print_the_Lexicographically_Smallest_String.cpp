class Solution {
public:
    string robotWithString(string s) {
        // Create a frequency map to store the counts of each character in the input string 's'.
        // This helps us quickly determine the smallest character remaining in 's' at any point.
        vector<int> freq(26, 0); 
        for (char ch : s) {
            freq[ch - 'a']++; // Increment count for the corresponding character
        }

        string paper = "";    // This string will store the lexicographically smallest string written on paper.
        string robot_t = "";  // This string simulates the robot's temporary string 't', acting as a stack.
        
        // Iterate through each character of the input string 's'.
        for (char cur_s_char : s) {
            // Operation 1: Move the first character from 's' to the robot's string 't'.
            robot_t.push_back(cur_s_char); 
            freq[cur_s_char - 'a']--; // Decrement its count in the frequency map.

            // Now, consider Operation 2: Try to move characters from 't' to 'paper'.
            // We can only move a character from 't' to 'paper' if it's less than or equal to
            // the smallest character still remaining in the original string 's' (and not yet moved to 't').
            while (!robot_t.empty()) {
                // Find the smallest character that is still available in the original 's' (i.e., not yet processed).
                char smallest_remaining_char = 'z' + 1; // Initialize with a character larger than 'z'.
                for (int i = 0; i < 26; ++i) {
                    if (freq[i] > 0) { // If this character still exists in 's' (or what's left of it)
                        smallest_remaining_char = (char)('a' + i); // This is our smallest remaining.
                        break; // No need to check further, we found the smallest.
                    }
                }

                // Decision point: Can we move the top of 'robot_t' to 'paper'?
                // We can if the character at the back of 'robot_t' is less than or equal to 
                // the smallest character that is still *not* in 'robot_t' and remains in the original 's'.
                if (robot_t.back() <= smallest_remaining_char) {
                    paper.push_back(robot_t.back()); // Perform Operation 2: Move from 't' to 'paper'.
                    robot_t.pop_back();              // Remove from 't'.
                } else {
                    // If the character at the back of 'robot_t' is greater than the smallest
                    // character remaining in 's', we *must* bring more characters from 's' to 't'
                    // to potentially find a smaller character in 's' to compare against later.
                    break; 
                }
            }
        }
        
        // After processing all characters from 's', any remaining characters in 'robot_t'
        // must be moved to 'paper' since there are no more characters to compare against from 's'.
        while (!robot_t.empty()) {
            paper.push_back(robot_t.back());
            robot_t.pop_back();
        }
        
        return paper; // Return the lexicographically smallest string.
    }
};
