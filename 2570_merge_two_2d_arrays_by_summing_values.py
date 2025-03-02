class Solution(object):
    def mergeArrays(self, a, b):
        x, y, r = 0, 0, []
        while x < len(a) or y < len(b):
            if y == len(b) or (x < len(a) and a[x][0] < b[y][0]): r.append(a[x]); x += 1
            elif x == len(a) or (y < len(b) and a[x][0] > b[y][0]): r.append(b[y]); y += 1
            else: r.append([a[x][0], a[x][1] + b[y][1]]); x += 1; y += 1
        return r
