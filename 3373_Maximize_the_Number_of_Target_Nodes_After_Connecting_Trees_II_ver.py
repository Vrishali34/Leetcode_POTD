from collections import deque

class Solution(object):
    def maxTargetNodes(self, edges1, edges2):
        n = len(edges1) + 1
        m = len(edges2) + 1

        adj_alpha = [[] for _ in range(n)]
        for link_a, link_b in edges1:
            adj_alpha[link_a].append(link_b)
            adj_alpha[link_b].append(link_a)

        adj_beta = [[] for _ in range(m)]
        for link_u, link_v in edges2:
            adj_beta[link_u].append(link_v)
            adj_beta[link_v].append(link_u)

        # Process first tree (alpha)
        alpha_depth_parities = [-1] * n
        queue_alpha = deque([(0, 0)])
        alpha_depth_parities[0] = 0
        even_alpha_nodes = 0
        odd_alpha_nodes = 0

        while queue_alpha:
            curr_node_alpha, parity_alpha = queue_alpha.popleft()
            if parity_alpha == 0:
                even_alpha_nodes += 1
            else:
                odd_alpha_nodes += 1

            for next_node_alpha in adj_alpha[curr_node_alpha]:
                if alpha_depth_parities[next_node_alpha] == -1:
                    alpha_depth_parities[next_node_alpha] = 1 - parity_alpha
                    queue_alpha.append((next_node_alpha, 1 - parity_alpha))

        # Process second tree (beta)
        beta_depth_parities = [-1] * m
        queue_beta = deque([(0, 0)])
        beta_depth_parities[0] = 0
        even_beta_nodes = 0
        odd_beta_nodes = 0

        while queue_beta:
            curr_node_beta, parity_beta = queue_beta.popleft()
            if parity_beta == 0:
                even_beta_nodes += 1
            else:
                odd_beta_nodes += 1

            for next_node_beta in adj_beta[curr_node_beta]:
                if beta_depth_parities[next_node_beta] == -1:
                    beta_depth_parities[next_node_beta] = 1 - parity_beta
                    queue_beta.append((next_node_beta, 1 - parity_beta))

        max_odd_target_in_beta = max(even_beta_nodes, odd_beta_nodes)

        final_counts = [0] * n
        for idx in range(n):
            current_even_count_alpha = 0
            if alpha_depth_parities[idx] == 0:
                current_even_count_alpha = even_alpha_nodes
            else:
                current_even_count_alpha = odd_alpha_nodes
            
            final_counts[idx] = current_even_count_alpha + max_odd_target_in_beta

        return final_counts
