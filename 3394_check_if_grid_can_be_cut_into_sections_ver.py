class Solution(object):
    def checkValidCuts(self, n, rectangles):
        def f(a, b): 
            x = sorted([[r[a], r[b]] for r in rectangles])
            s = 1; e = x[0][1]
            for i in x[1:]:
                if i[0] >= e: s += 1; e = i[1]
                else: e = max(e, i[1])
            return s > 2
        return f(0,2) or f(1,3)
