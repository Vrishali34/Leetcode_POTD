class Solution(object):
    def sortColors(self, x):
        a, b, c = 0, 0, len(x) - 1
        while b <= c:
            if x[b] == 0: x[a], x[b], a, b = x[b], x[a], a+1, b+1
            elif x[b] == 2: x[b], x[c], c = x[c], x[b], c-1
            else: b += 1
