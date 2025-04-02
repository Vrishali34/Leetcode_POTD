class Solution(object):
    def maximumTripletValue(self, v):
        ans, t = 0, 0
        s = [0] * len(v)
        for i in range(len(v) - 2, -1, -1): s[i] = max(s[i + 1], v[i + 1])
        for j in range(1, len(v) - 1):
            t = max(t, v[j - 1])
            ans = max(ans, (t - v[j]) * s[j])
        return ans
