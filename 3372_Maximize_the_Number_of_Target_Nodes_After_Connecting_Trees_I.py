import collections

class Solution(object):
    def maxTargetNodes(self, edges1, edges2, k):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        
        def calculate_reachable(start_node, distance_limit, num_nodes, adj_list):
            q = collections.deque([(start_node, 0)])
            distances = [-1] * num_nodes
            distances[start_node] = 0
            count = 0

            while q:
                u, d = q.popleft()

                if d > distance_limit:
                    continue
                count += 1

                for v in adj_list[u]:
                    if distances[v] == -1:
                        distances[v] = d + 1
                        q.append((v, d + 1))
            return count

        n = len(edges1) + 1
        m = len(edges2) + 1

        adj1 = [[] for _ in range(n)]
        for u, v in edges1:
            adj1[u].append(v)
            adj1[v].append(u)

        adj2 = [[] for _ in range(m)]
        for u, v in edges2:
            adj2[u].append(v)
            adj2[v].append(u)

        counts1 = [calculate_reachable(i, k, n, adj1) for i in range(n)]

        max_counts2 = max(calculate_reachable(j, k - 1, m, adj2) for j in range(m))
        
        answer = [counts1[i] + max_counts2 for i in range(n)]

        return answer
