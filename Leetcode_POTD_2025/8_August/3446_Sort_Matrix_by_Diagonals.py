class Solution(object):
    def sortMatrix(self, grid):
        n = len(grid)
        bottom_diags = {}
        top_diags = {}

        for r in range(n):
            for c in range(n):
                if r >= c:
                    bottom_diags.setdefault(r - c, []).append(grid[r][c])
                else:
                    top_diags.setdefault(r - c, []).append(grid[r][c])

        for key in bottom_diags:
            bottom_diags[key].sort(reverse=True)
        
        for key in top_diags:
            top_diags[key].sort()

        for r in range(n):
            for c in range(n):
                if r >= c:
                    grid[r][c] = bottom_diags[r - c].pop(0)
                else:
                    grid[r][c] = top_diags[r - c].pop(0)

        return grid
