class Solution(object):
    def minSum(self, m, n):
        s1, z1 = sum(i for i in m if i), m.count(0)
        s2, z2 = sum(i for i in n if i), n.count(0)
        return -1 if (not z1 and s1 < s2 + z2) or (not z2 and s2 < s1 + z1) else max(s1 + z1, s2 + z2)
