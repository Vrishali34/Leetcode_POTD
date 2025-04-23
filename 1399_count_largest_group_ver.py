class Solution(object):
    def countLargestGroup(self, n):
        from collections import Counter
        grp = Counter(sum(map(int, str(i))) for i in range(1, n + 1))
        m = max(grp.values())
        return sum(v == m for v in grp.values())
