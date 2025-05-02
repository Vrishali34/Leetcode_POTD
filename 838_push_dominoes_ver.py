class Solution(object):
    def pushDominoes(self, s):
        n = len(s)
        net = [0] * n
        f = 0
        for i in range(n):
            if s[i] == 'R': f = n
            elif s[i] == 'L': f = 0
            else: f = max(f - 1, 0)
            net[i] += f
        f = 0
        for i in range(n - 1, -1, -1):
            if s[i] == 'L': f = n
            elif s[i] == 'R': f = 0
            else: f = max(f - 1, 0)
            net[i] -= f
        return ''.join('R' if x > 0 else 'L' if x < 0 else '.' for x in net)
