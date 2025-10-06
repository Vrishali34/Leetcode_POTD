class Solution(object):
    def swimInWater(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        import heapq
        n = len(grid)
        cost_map = {}
        cost_map[(0, 0)] = grid[0][0]
        p_q = [(grid[0][0], 0, 0)]
        
        while p_q:
            max_elev, row, col = heapq.heappop(p_q)
            
            if row == n - 1 and col == n - 1:
                return max_elev
            
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                n_r, n_c = row + dr, col + dc
                
                if 0 <= n_r < n and 0 <= n_c < n:
                    new_max = max(max_elev, grid[n_r][n_c])
                    if (n_r, n_c) not in cost_map or new_max < cost_map[(n_r, n_c)]:
                        cost_map[(n_r, n_c)] = new_max
                        heapq.heappush(p_q, (new_max, n_r, n_c))
