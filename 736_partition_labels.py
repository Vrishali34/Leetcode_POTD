class Solution(object):
    def partitionLabels(self, z):
        q = [0] * 128
        for i, c in enumerate(z): q[ord(c)] = i
        r, a, b = [], 0, 0
        for i, c in enumerate(z):
            a = max(a, q[ord(c)])
            if i == a:
                r.append(i - b + 1)
                b = i + 1
        return r
