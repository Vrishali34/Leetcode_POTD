class Solution(object):
    def minimumArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows = len(grid)
        cols = len(grid[0])
        min_r, max_r = rows, -1
        min_c, max_c = cols, -1

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    min_r = min(min_r, r)
                    max_r = max(max_r, r)
                    min_c = min(min_c, c)
                    max_c = max(max_c, c)
        
        return (max_r - min_r + 1) * (max_c - min_c + 1)
