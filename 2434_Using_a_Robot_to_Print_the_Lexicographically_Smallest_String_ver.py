class Solution(object):
    def robotWithString(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        
        # 1. Precompute Suffix Minimums:
        # suff_min[i] will store the smallest character from s[i] to s[n-1].
        # Initialize with a character larger than 'z'.
        suff_min = ['{'] * (n + 1) # '{' is lexicographically greater than 'z'
        
        # Iterate from right to left to populate suff_min
        for i in range(n - 1, -1, -1):
            suff_min[i] = min(s[i], suff_min[i + 1])

        paper = []  # To store the characters written on paper (final result)
        robot_t = []  # To simulate the robot's temporary string 't' (acts as a stack)

        # 2. Iterate through the input string 's'
        for i in range(n):
            current_s_char = s[i]
            
            # Operation 1: Move the current character from 's' to 'robot_t'
            robot_t.append(current_s_char)

            # 3. Consider Operation 2: Try to move characters from 'robot_t' to 'paper'
            # We can pop from robot_t and add to paper if the character at the top of robot_t
            # is less than or equal to the smallest character remaining in the unprocessed part of 's'.
            # The smallest character in the *remaining* part of 's' is given by suff_min[i+1].
            while robot_t and robot_t[-1] <= suff_min[i + 1]:
                paper.append(robot_t.pop())
        
        # 4. After processing all characters from 's', any remaining characters in 'robot_t'
        # must be moved to 'paper' (since there are no more characters from 's' to consider).
        while robot_t:
            paper.append(robot_t.pop())
            
        return "".join(paper) # Join the list of characters to form the final string
