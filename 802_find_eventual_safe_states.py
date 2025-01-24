class Solution(object):
    def eventualSafeNodes(self, graph):
        n = len(graph)
        visit, cycle, safe = [False] * n, [False] * n, [False] * n

        def dfs(node):
            if visit[node]:
                return safe[node]
            visit[node] = cycle[node] = True
            for nei in graph[node]:
                if cycle[nei] or not dfs(nei):
                    safe[node] = False
                    return False
            cycle[node] = False
            safe[node] = True
            return True

        for i in range(n):
            dfs(i)
        return [i for i in range(n) if safe[i]]
