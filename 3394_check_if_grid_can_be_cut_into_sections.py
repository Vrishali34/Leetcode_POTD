class Solution(object):
    def checkValidCuts(self, n, rectangles):
        def count(dir1, dir2):
            a = sorted([(r[dir1], r[dir2]) for r in rectangles])
            res, end = 1, a[0][1]
            for s, e in a[1:]:
                if s >= end:
                    res += 1
                    end = e
                else:
                    end = max(end, e)
            return res >= 3
        return count(0, 2) or count(1, 3)
