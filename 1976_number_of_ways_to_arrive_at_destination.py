class Solution(object):
    def countPaths(self, z, q):
        import heapq
        g = [[] for _ in range(z)]
        for a, b, c in q:
            g[a].append((b, c))
            g[b].append((a, c))
        d = [float('inf')] * z
        w = [0] * z
        d[0] = 0
        w[0] = 1
        h = [(0, 0)]
        while h:
            t, u = heapq.heappop(h)
            if t > d[u]: continue
            for v, c in g[u]:
                s = t + c
                if s < d[v]:
                    d[v], w[v] = s, w[u]
                    heapq.heappush(h, (s, v))
                elif s == d[v]:
                    w[v] = (w[v] + w[u]) % 1000000007
        return w[-1]
