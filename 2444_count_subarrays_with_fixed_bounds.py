class Solution(object):
    def countSubarrays(self, x, y, z):
        r, u, v, w = 0, -1, -1, -1
        for i in range(len(x)):
            if x[i] < y or x[i] > z: w = i
            if x[i] == y: u = i
            if x[i] == z: v = i
            r += max(0, min(u, v) - w)
        return r
