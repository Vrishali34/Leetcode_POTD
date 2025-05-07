import heapq

class Solution(object):
    def minTimeToReach(self, mT):
        r, c = len(mT), len(mT[0])
        d = [[float('inf')] * c for _ in range(r)]
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        pq = [(0, 0, 0)]
        d[0][0] = 0
        
        while pq:
            t, x, y = heapq.heappop(pq)
            if x == r - 1 and y == c - 1:
                return t
            if t > d[x][y]:
                continue
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < r and 0 <= ny < c:
                    wait = max(0, mT[nx][ny] - d[x][y])
                    newT = t + 1 + wait
                    if newT < d[nx][ny]:
                        d[nx][ny] = newT
                        heapq.heappush(pq, (newT, nx, ny))
        return -1
