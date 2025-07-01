class Solution(object):
    def possibleStringCount(self, z):
        s = 1
        i = 0
        while i < len(z):
            j = i
            while j + 1 < len(z) and z[j + 1] == z[i]: j += 1
            s += j - i
            i = j + 1
        return s
