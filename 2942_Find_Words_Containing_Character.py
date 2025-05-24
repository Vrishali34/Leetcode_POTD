class Solution(object):
    def findWordsContaining(self, words, x):
        e = []
        for i in range(len(words)):
            if x in words[i]:
                e.append(i)
        return e
