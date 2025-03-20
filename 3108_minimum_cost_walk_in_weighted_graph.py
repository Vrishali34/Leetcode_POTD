class Solution(object):
    def minimumCost(self, n, edges, query):
        parent = list(range(n))
        rank = [0] * n
        weight = [(1 << 17) - 1] * n  # Initialize with max bitwise value

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y, w):
            rootX, rootY = find(x), find(y)
            val = weight[rootX] & weight[rootY] & w
            weight[rootX] = weight[rootY] = val
            if rootX != rootY:
                if rank[rootX] < rank[rootY]:
                    parent[rootX] = rootY
                elif rank[rootX] > rank[rootY]:
                    parent[rootY] = rootX
                else:
                    parent[rootX] = rootY
                    rank[rootY] += 1

        for u, v, w in edges:
            union(u, v, w)

        return [weight[find(a)] if find(a) == find(b) else -1 for a, b in query]
