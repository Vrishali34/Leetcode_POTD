import collections

class Solution(object):
    def minimumDeletions(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        freq_map = collections.Counter(word)
        unique_freqs = sorted(list(freq_map.values()))
        min_deletions = float('inf')

        for low_freq_target in unique_freqs:
            current_deletions = 0
            for char_freq in freq_map.values():
                if char_freq < low_freq_target:
                    current_deletions += char_freq
                elif char_freq > low_freq_target + k:
                    current_deletions += char_freq - (low_freq_target + k)
            min_deletions = min(min_deletions, current_deletions)
            
        return min_deletions
