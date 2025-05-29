from collections import deque

class Solution(object):
    def _compute_bipartition_counts(self, num_nodes, adj, node_depth_parities):
        """
        Helper method to perform BFS and compute partition counts (even/odd depth from root 0)
        and store the depth parity for each node.
        """
        # Initialize all nodes as unvisited (-1)
        for i in range(num_nodes):
            node_depth_parities[i] = -1

        q = deque()  # Stores [node, depth_parity_from_root]

        # Start BFS from node 0, assuming it's at depth 0 (even parity)
        q.append([0, 0])
        node_depth_parities[0] = 0

        even_depth_count = 0
        odd_depth_count = 0

        while q:
            current_node, current_parity = q.popleft()

            if current_parity == 0:
                even_depth_count += 1
            else:
                odd_depth_count += 1

            for neighbor in adj[current_node]:
                if node_depth_parities[neighbor] == -1:  # If neighbor not visited
                    node_depth_parities[neighbor] = 1 - current_parity  # Neighbor's depth parity is opposite
                    q.append([neighbor, 1 - current_parity])
        
        return [even_depth_count, odd_depth_count]

    def maxTargetNodes(self, edges1, edges2):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :rtype: List[int]
        """
        n = len(edges1) + 1  # Number of nodes in the first tree
        m = len(edges2) + 1  # Number of nodes in the second tree

        # Build adjacency list for the first tree
        adj1 = [[] for _ in range(n)]
        for u, v in edges1:
            adj1[u].append(v)
            adj1[v].append(u)

        # Build adjacency list for the second tree
        adj2 = [[] for _ in range(m)]
        for u, v in edges2:
            adj2[u].append(v)
            adj2[v].append(u)

        # Process Tree 1
        # node_parities_T1 will store the depth parity (0 for even, 1 for odd) for each node in Tree 1
        # relative to an arbitrary root (node 0).
        node_parities_T1 = [0] * n
        counts_T1_from_root0 = self._compute_bipartition_counts(n, adj1, node_parities_T1)
        even_partition_size_T1 = counts_T1_from_root0[0]  # Number of nodes in T1 with even depth from root 0
        odd_partition_size_T1 = counts_T1_from_root0[1]   # Number of nodes in T1 with odd depth from root 0

        # Process Tree 2
        # node_parities_T2 will store the depth parity (0 for even, 1 for odd) for each node in Tree 2
        # relative to an arbitrary root (node 0).
        node_parities_T2 = [0] * m
        counts_T2_from_root0 = self._compute_bipartition_counts(m, adj2, node_parities_T2)
        even_partition_size_T2 = counts_T2_from_root0[0]  # Number of nodes in T2 with even depth from root 0
        odd_partition_size_T2 = counts_T2_from_root0[1]   # Number of nodes in T2 with odd depth from root 0

        # Find the maximum number of nodes in Tree 2 that can be at an odd distance
        # from *any* chosen connection point 'j' in Tree 2.
        # This is simply the larger of the two partition sizes in Tree 2.
        max_odd_dist_nodes_T2 = max(even_partition_size_T2, odd_partition_size_T2)

        # Compute Final Answer
        answer = [0] * n
        for i in range(n):
            nodes_even_dist_from_i_in_T1 = 0 # This is 'even[i]' from Hint 1
            
            # If node 'i' is in the 'even depth' partition of Tree 1 (relative to root 0),
            # then nodes at even distance from 'i' are all nodes in that 'even depth' partition.
            if node_parities_T1[i] == 0: 
                nodes_even_dist_from_i_in_T1 = even_partition_size_T1
            # If node 'i' is in the 'odd depth' partition of Tree 1 (relative to root 0),
            # then nodes at even distance from 'i' are all nodes in that 'odd depth' partition.
            else: 
                nodes_even_dist_from_i_in_T1 = odd_partition_size_T1
            
            # Total target nodes for 'i' = (nodes in T1 even dist from i) + (max nodes in T2 odd dist from j)
            answer[i] = nodes_even_dist_from_i_in_T1 + max_odd_dist_nodes_T2

        return answer
