class Solution(object):
    def divideArray(self, t):
        s = set()
        for r in t:
            s.remove(r) if r in s else s.add(r)
        return not s
