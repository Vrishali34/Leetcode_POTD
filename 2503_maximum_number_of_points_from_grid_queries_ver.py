import heapq

class Solution(object):
    def maxPoints(self, a, b):
        r, c = len(a), len(a[0])
        v = [[0]*c for _ in range(r)]
        q = [(a[0][0], 0, 0)]
        v[0][0] = 1
        z = [0]*len(b)
        s = sorted(range(len(b)), key=lambda x: b[x])
        d = [(0,1),(1,0),(0,-1),(-1,0)]
        t = 0

        for i in s:
            while q and q[0][0] < b[i]:
                _, x, y = heapq.heappop(q)
                t += 1
                for dx, dy in d:
                    nx, ny = x+dx, y+dy
                    if 0<=nx<r and 0<=ny<c and not v[nx][ny]:
                        v[nx][ny] = 1
                        heapq.heappush(q, (a[nx][ny], nx, ny))
            z[i] = t
        return z
