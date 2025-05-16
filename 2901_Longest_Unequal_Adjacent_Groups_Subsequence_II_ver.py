class Solution(object):
    def getWordsInLongestSubsequence(self, w, g):
        z, t = [], -9
        for a, b in zip(w, g):
            if b ^ t:
                z += [a]
                t = b
        return z
