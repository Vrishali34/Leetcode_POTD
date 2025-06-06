class Solution(object):
    def robotWithString(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Initialize a frequency array (list in Python) to count character occurrences.
        # freq[0] for 'a', freq[1] for 'b', and so on.
        freq = [0] * 26
        for char_code in s:
            freq[ord(char_code) - ord('a')] += 1

        paper = []  # This list will store characters written on paper (final result).
        robot_t = []  # This list will simulate the robot's temporary string 't' (acting as a stack).

        # Iterate through each character in the input string 's'.
        for cur_s_char in s:
            # Operation 1: Move the first character from 's' to the robot's string 't'.
            robot_t.append(cur_s_char)
            freq[ord(cur_s_char) - ord('a')] -= 1  # Decrement its count in the frequency map.

            # Now, consider Operation 2: Try to move characters from 't' to 'paper'.
            # We can only move a character from 't' to 'paper' if it's less than or equal to
            # the smallest character still remaining in the original string 's' (and not yet moved to 't').
            while robot_t:  # Equivalent to while (!robot_t.empty())
                # Find the smallest character that is still available in the original 's'
                # (i.e., not yet processed and moved to 't').
                smallest_remaining_char = chr(ord('z') + 1)  # Initialize with a character larger than 'z'.
                for i in range(26):
                    if freq[i] > 0:  # If this character still exists in 's'
                        smallest_remaining_char = chr(ord('a') + i)  # This is our smallest remaining.
                        break  # No need to check further, we found the smallest.

                # Decision point: Can we move the top of 'robot_t' to 'paper'?
                # We can if the character at the back (top) of 'robot_t' is less than or equal to
                # the smallest character that is still *not* in 'robot_t' and remains in the original 's'.
                if robot_t[-1] <= smallest_remaining_char:  # robot_t[-1] gets the last element (top of stack)
                    paper.append(robot_t.pop())  # Perform Operation 2: Move from 't' to 'paper' and remove from 't'.
                else:
                    # If the character at the back of 'robot_t' is greater than the smallest
                    # character remaining in 's', we *must* bring more characters from 's' to 't'
                    # to potentially find a smaller character in 's' to compare against later.
                    break

        # After processing all characters from 's', any remaining characters in 'robot_t'
        # must be moved to 'paper' since there are no more characters to compare against from 's'.
        while robot_t:
            paper.append(robot_t.pop())

        return "".join(paper)  # Join the list of characters to form the final string.
