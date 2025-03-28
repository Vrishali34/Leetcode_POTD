import heapq

class Solution(object):
    def maxPoints(self, grid, queries):
        m, n = len(grid), len(grid[0])
        dirs = [(0,1), (1,0), (0,-1), (-1,0)]

        idx = sorted(range(len(queries)), key=lambda i: queries[i])
        res = [0] * len(queries)

        seen = [[False]*n for _ in range(m)]
        heap = [(grid[0][0], 0, 0)]
        seen[0][0] = True

        cnt = 0
        q_ptr = 0

        for i in idx:
            q = queries[i]
            while heap and heap[0][0] < q:
                val, x, y = heapq.heappop(heap)
                cnt += 1
                for dx, dy in dirs:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and not seen[nx][ny]:
                        seen[nx][ny] = True
                        heapq.heappush(heap, (grid[nx][ny], nx, ny))
            res[i] = cnt
        return res
