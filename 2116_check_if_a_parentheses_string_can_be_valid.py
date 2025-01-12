class Solution(object):
    def canBeValid(self, a, b):
        c = len(a)
        if c % 2: return False
        d = 0
        for e in range(c):
            d += 1 if a[e] == '(' or b[e] == '0' else -1
            if d < 0: return False
        d = 0
        for e in range(c - 1, -1, -1):
            d += 1 if a[e] == ')' or b[e] == '0' else -1
            if d < 0: return False
        return True
