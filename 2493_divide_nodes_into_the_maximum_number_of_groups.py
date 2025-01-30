from collections import deque, defaultdict

class Solution(object):
    def magnificentSets(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        g = [[] for _ in range(n)]
        parent = list(range(n))
        rank = [0] * n
        color = [-1] * n
        
        for u, v in edges:
            u, v = u - 1, v - 1
            g[u].append(v)
            g[v].append(u)
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            rootX, rootY = find(x), find(y)
            if rootX != rootY:
                if rank[rootX] > rank[rootY]:
                    parent[rootY] = rootX
                elif rank[rootX] < rank[rootY]:
                    parent[rootX] = rootY
                else:
                    parent[rootY] = rootX
                    rank[rootX] += 1

        def is_bipartite(start):
            q = deque([start])
            color[start] = 0
            while q:
                node = q.popleft()
                for nei in g[node]:
                    if color[nei] == -1:
                        color[nei] = 1 - color[node]
                        union(node, nei)
                        q.append(nei)
                    elif color[nei] == color[node]:
                        return False
            return True

        for i in range(n):
            if color[i] == -1 and not is_bipartite(i):
                return -1

        groups = defaultdict(list)
        for i in range(n):
            groups[find(i)].append(i)

        def bfs(src):
            q = deque([src])
            visited = set([src])
            level = 0
            while q:
                for _ in range(len(q)):
                    node = q.popleft()
                    for nei in g[node]:
                        if nei not in visited:
                            visited.add(nei)
                            q.append(nei)
                level += 1
            return level

        res = 0
        for group in groups.values():
            res += max(bfs(node) for node in group)
        
        return res
