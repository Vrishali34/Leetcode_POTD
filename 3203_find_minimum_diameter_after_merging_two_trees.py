class Solution(object):
    def calculate_diameter(self, edges):
        from collections import defaultdict, deque
        graph = defaultdict(list)
        degree = [0] * (len(edges) + 1)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
            degree[u] += 1
            degree[v] += 1
        queue = deque(i for i in range(len(degree)) if degree[i] == 1)
        remaining = len(edges) + 1
        depth = 0
        while remaining > 2:
            size = len(queue)
            remaining -= size
            depth += 1
            for _ in range(size):
                node = queue.popleft()
                for neighbor in graph[node]:
                    degree[neighbor] -= 1
                    if degree[neighbor] == 1:
                        queue.append(neighbor)
        return 2 * depth + 1 if remaining == 2 else 2 * depth

    def minimumDiameterAfterMerge(self, edges1, edges2):
        d1 = self.calculate_diameter(edges1)
        d2 = self.calculate_diameter(edges2)
        return max(d1, d2, (d1 + 1) // 2 + (d2 + 1) // 2 + 1)
