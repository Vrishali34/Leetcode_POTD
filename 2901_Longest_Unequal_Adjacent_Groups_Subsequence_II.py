class Solution(object):
    def getWordsInLongestSubsequence(self, words, groups):
        res, prev = [], -1
        for w, g in zip(words, groups):
            if g != prev:
                res.append(w)
                prev = g
        return res
