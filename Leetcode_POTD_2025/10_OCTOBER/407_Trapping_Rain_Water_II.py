import heapq

class Solution(object):
    def trapRainWater(self, terrain_grid):
        if not terrain_grid or not terrain_grid[0]: return 0
        
        m, n = len(terrain_grid), len(terrain_grid[0])
        if m < 3 or n < 3: return 0

        border_walls = []
        is_visited = [[False] * n for _ in range(m)]
        
        for r in range(m):
            for c in range(n):
                if r == 0 or r == m - 1 or c == 0 or c == n - 1:
                    heapq.heappush(border_walls, (terrain_grid[r][c], r, c))
                    is_visited[r][c] = True

        trapped_liquid = 0
        max_height = 0
        
        while border_walls:
            h, r, c = heapq.heappop(border_walls)
            max_height = max(max_height, h)
            
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nr, nc = r + dr, c + dc
                
                if 0 <= nr < m and 0 <= nc < n and not is_visited[nr][nc]:
                    trapped_liquid += max(0, max_height - terrain_grid[nr][nc])
                    
                    new_height = max(max_height, terrain_grid[nr][nc])
                    heapq.heappush(border_walls, (new_height, nr, nc))
                    is_visited[nr][nc] = True
                    
        return trapped_liquid
