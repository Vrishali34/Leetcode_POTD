class Solution(object):
    def df(self, p, q):
        x, y = len(p), len(q)
        return x <= y and q.startswith(p) and q.endswith(p)

    def countPrefixSuffixPairs(self, words):
        res = 0
        for a in range(len(words)):
            for b in range(a + 1, len(words)):
                if self.df(words[a], words[b]):
                    res += 1
        return res
