class Solution(object):
    def lengthAfterTransformations(self, s, t):
        """
        :type s: str
        :type t: int
        :rtype: int
        """
        M = 1000000007
        freq = [0] * 26
        
       
        for c in s:
            freq[ord(c) - ord('a')] += 1

        
        for _ in range(t):
            next_freq = [0] * 26
            for i in range(26):
                if i == 25:
                    next_freq[0] = (next_freq[0] + freq[i]) % M
                    next_freq[1] = (next_freq[1] + freq[i]) % M
                else:
                    next_freq[i + 1] = (next_freq[i + 1] + freq[i]) % M
            freq = next_freq

        
        result = sum(freq) % M
        
        return result
