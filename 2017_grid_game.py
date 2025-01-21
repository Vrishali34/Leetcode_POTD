class Solution(object):
    def gridGame(self, grid):
        n = len(grid[0])
        totalTop = sum(grid[0])
        totalBot = 0
        res = float('inf')
        for i in range(n):
            totalTop -= grid[0][i]
            res = min(res, max(totalTop, totalBot))
            totalBot += grid[1][i]
        return res
