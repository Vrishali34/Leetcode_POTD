from collections import defaultdict

class Solution:
    def mostProfitablePath(self, edges, bob, amount):
        g, m, mx = defaultdict(list), {}, float('-inf')

        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        def dfs_bob(n, t, v):
            v.add(n)
            m[n] = t
            if n == 0: return True
            for nb in g[n]:
                if nb not in v and dfs_bob(nb, t + 1, v):
                    return True
            del m[n]
            return False

        def dfs_alice(n, t, p, v):
            nonlocal mx
            v.add(n)
            p += amount[n] if n not in m or t < m[n] else amount[n] // 2 if t == m[n] else 0
            if len(g[n]) == 1 and n != 0:
                mx = max(mx, p)
            for nb in g[n]:
                if nb not in v:
                    dfs_alice(nb, t + 1, p, v)

        dfs_bob(bob, 0, set())
        dfs_alice(0, 0, 0, set())
        return mx
