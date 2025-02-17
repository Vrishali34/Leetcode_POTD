from collections import Counter

class Solution:
    def numTilePossibilities(self, z):
        p = Counter(z)
        def r():
            s = 0
            for c in p:
                if p[c]:
                    p[c] -= 1
                    s += 1 + r()
                    p[c] += 1
            return s
        return r()
