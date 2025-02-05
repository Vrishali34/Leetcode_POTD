class Solution(object):
    def areAlmostEqual(self, s1, s2):
        if s1 == s2:
            return True
        n = len(s1)
        s2_list = list(s2)
        for i in range(n - 1):
            for j in range(i + 1, n):
                s2_list[i], s2_list[j] = s2_list[j], s2_list[i]
                if ''.join(s2_list) == s1:
                    return True
                s2_list = list(s2) 
        return False
