class Solution(object):
    def answerString(self, word, numFriends):
        if numFriends == 1: return word
        res = ""
        k = len(word) - numFriends + 1
        for i in range(len(word)):
            res = max(res, word[i:i+k])
        return res
