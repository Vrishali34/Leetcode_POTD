class Solution(object):
    def getLongestSubsequence(self, words, groups):
        p = []
        l = -1
        for i in range(len(words)):
            if l == -1 or groups[i] != groups[l]:
                p.append(words[i])
                l = i
        return p
