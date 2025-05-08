import heapq
class Solution(object):
    def minTimeToReach(self, g):
        r, c = len(g), len(g[0])
        v = [[0]*c for _ in range(r)]
        q = [(0, 0, 0, 1)]
        D = [(0,1),(1,0),(-1,0),(0,-1)]
        while q:
            t, x, y, s = heapq.heappop(q)
            if x == r-1 and y == c-1: return t
            if v[x][y]: continue
            v[x][y] = 1
            for dx, dy in D:
                nx, ny = x+dx, y+dy
                if 0<=nx<r and 0<=ny<c and not v[nx][ny]:
                    wait = max(t, g[nx][ny])
                    heapq.heappush(q, (wait + s, nx, ny, 3-s))
        return -1
