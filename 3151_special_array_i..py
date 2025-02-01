class Solution(object):
    def isArraySpecial(self, f):
        return all(f[h] % 2 != f[h + 1] % 2 for h in range(len(f) - 1))
