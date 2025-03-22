class Solution(object):
    def countCompleteComponents(self, n, edges):
        from collections import defaultdict

        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        vis = [False] * n
        res = 0

        def dfs(u, comp):
            vis[u] = True
            comp.append(u)
            for v in g[u]:
                if not vis[v]:
                    dfs(v, comp)

        for i in range(n):
            if not vis[i]:
                comp = []
                dfs(i, comp)
                total_deg = sum(len(g[v]) for v in comp)
                sz = len(comp)
                if total_deg // 2 == sz * (sz - 1) // 2:
                    res += 1
        return res
