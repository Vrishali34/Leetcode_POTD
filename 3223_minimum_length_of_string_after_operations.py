class Solution(object):
    def minimumLength(self, x):
        z = {}
        for c in x:
            z[c] = z.get(c, 0) + 1
        d = 0
        for count in z.values():
            if count > 2:
                d += count - (1 if count % 2 else 2)
        return len(x) - d
