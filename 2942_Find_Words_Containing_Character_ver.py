class Solution(object):
    def findWordsContaining(self, words, x):
        g = []
        l = 0
        for w in words:
            if x in w:
                g.append(l)
            l += 1
        return g
