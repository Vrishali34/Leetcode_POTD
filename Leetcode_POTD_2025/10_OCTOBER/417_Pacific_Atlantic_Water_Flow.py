class Solution(object):
    def pacificAtlantic(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n = len(heights), len(heights[0])
        pac_reach, atl_reach = set(), set()
        
        def flow_finder(r, c, ocean_set):
            if (r, c) in ocean_set: return
            ocean_set.add((r, c))
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and heights[nr][nc] >= heights[r][c]:
                    flow_finder(nr, nc, ocean_set)

        for r in range(m):
            flow_finder(r, 0, pac_reach)
            flow_finder(r, n - 1, atl_reach)
        
        for c in range(n):
            flow_finder(0, c, pac_reach)
            flow_finder(m - 1, c, atl_reach)

        return [list(coord) for coord in pac_reach.intersection(atl_reach)]
