class Solution(object):
    def minOperations(self, r):
        x = 0
        for i in range(len(r) - 2):
            if not r[i]: r[i], r[i + 1], r[i + 2], x = 1 - r[i], 1 - r[i + 1], 1 - r[i + 2], x + 1
        return -1 if any(v == 0 for v in r) else x
