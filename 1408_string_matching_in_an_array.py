class Solution(object):
    def stringMatching(self, f):
        g = []
        r = len(f)
        for o in range(r):
            for p in range(r):
                if o != p and f[p].find(f[o]) != -1:
                    g.append(f[o])
                    break
        return g
