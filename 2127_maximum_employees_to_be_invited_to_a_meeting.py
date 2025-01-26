class Solution(object):
    def maximumInvitations(self, fav):
        n = len(fav)
        deg = [0] * n
        dist = [0] * n
        visited = [False] * n
        for f in fav:
            deg[f] += 1
        queue = [i for i in range(n) if deg[i] == 0]
        for i in queue:
            visited[i] = True
            dist[fav[i]] = dist[i] + 1
            deg[fav[i]] -= 1
            if deg[fav[i]] == 0:
                queue.append(fav[i])
        cycles, pairs = 0, 0
        for i in range(n):
            if not visited[i]:
                count, x = 0, i
                while not visited[x]:
                    visited[x] = True
                    x = fav[x]
                    count += 1
                if count == 2:
                    pairs += 2 + dist[i] + dist[fav[i]]
                else:
                    cycles = max(cycles, count)
        return max(cycles, pairs)
