class Solution(object):
    def numberOfSubstrings(self, s):
        count, left = 0, 0
        freq = [0] * 3

        for c in s:
            freq[ord(c) - ord('a')] += 1

            while all(freq):
                freq[ord(s[left]) - ord('a')] -= 1
                left += 1

            count += left

        return count
