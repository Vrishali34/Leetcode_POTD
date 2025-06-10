from collections import Counter

class Solution(object):
    def maxDifference(self, s):
        """
        :type s: str
        :rtype: int
        """
        freq_map = Counter(s)

        max_odd_freq = 0
        min_even_freq = float('inf')

        for freq in freq_map.values():
            if freq % 2 != 0:
                max_odd_freq = max(max_odd_freq, freq)
            else:
                min_even_freq = min(min_even_freq, freq)
        
        return max_odd_freq - min_even_freq
