class Solution(object):
    def minimumRecolors(self, m, n):
        x = 0
        y = float('inf')
        for i in range(len(m)):
            if i >= n:
                x -= m[i - n] == 'W'
            x += m[i] == 'W'
            if i >= n - 1:
                y = min(y, x)
        return y
