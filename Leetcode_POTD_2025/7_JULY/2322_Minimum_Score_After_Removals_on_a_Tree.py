import collections

class Solution(object):
    def minimumScore(self, nums, edges):
        """
        :type nums: List[int]
        :type edges: List[List[int]]
        :rtype: int
        """
        num_nodes = len(nums)
        
        # Adjacency list to represent the tree.
        adj_list = collections.defaultdict(list)
        for u, v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)

        # Arrays to store subtree XOR sums, and DFS entry/exit times.
        subtree_xor_sums = [0] * num_nodes
        entry_times = [0] * num_nodes
        exit_times = [0] * num_nodes
        
        # Global counter for DFS timestamps.
        self.dfs_time_counter = 0

        # Helper function for Depth First Search traversal.
        # It calculates the XOR sum of all nodes in the subtree rooted at current_node
        # and records the entry and exit times for each node.
        def calculate_subtree_data(current_node, parent_node):
            # Record the time when we first visit this node.
            entry_times[current_node] = self.dfs_time_counter
            self.dfs_time_counter += 1
            
            # Initialize the XOR sum for the current subtree with the current node's value.
            subtree_xor_sums[current_node] = nums[current_node]
            
            # Iterate through all neighbors of the current node.
            for neighbor in adj_list[current_node]:
                # Skip the parent node to avoid going back up the tree.
                if neighbor == parent_node:
                    continue
                # Recursively call DFS for the neighbor (child node).
                calculate_subtree_data(neighbor, current_node)
                # XOR the child's subtree sum into the current node's sum.
                subtree_xor_sums[current_node] ^= subtree_xor_sums[neighbor]
            
            # Record the time when we finish visiting all descendants of this node.
            exit_times[current_node] = self.dfs_time_counter
            self.dfs_time_counter += 1

        # Helper function to determine if 'potential_descendant' is within the subtree
        # rooted at 'potential_ancestor' using DFS entry and exit times.
        def is_descendant_of(potential_ancestor, potential_descendant):
            return entry_times[potential_ancestor] <= entry_times[potential_descendant] and \
                   exit_times[potential_ancestor] >= exit_times[potential_descendant]

        # Start DFS from node 0 (assuming it's the root of the tree).
        calculate_subtree_data(0, -1)

        # The total XOR sum of all nodes in the entire tree.
        total_tree_xor_val = subtree_xor_sums[0]
        
        # Initialize the minimum possible score to a very large value.
        min_possible_score = float('inf')

        # Iterate through all possible pairs of distinct nodes (i, j) to simulate
        # removing the edges that connect them to their respective parents.
        # We consider nodes from 1 up to num_nodes - 1, as node 0 is the root
        # and its removal as a cut point would mean removing the entire tree.
        for i in range(1, num_nodes):
            for j in range(i + 1, num_nodes):
                xor_comp1, xor_comp2, xor_comp3 = 0, 0, 0

                # Case 1: Node 'j' is a descendant of node 'i'.
                # This implies the edge leading to 'j' is within the subtree rooted at 'i'.
                # The three components' XORs would be:
                # 1. Subtree rooted at j.
                # 2. Subtree rooted at i, excluding the subtree rooted at j.
                # 3. The rest of the tree (total XOR minus subtree rooted at i).
                if is_descendant_of(i, j):
                    xor_comp1 = subtree_xor_sums[j]
                    xor_comp2 = subtree_xor_sums[i] ^ subtree_xor_sums[j]
                    xor_comp3 = total_tree_xor_val ^ subtree_xor_sums[i]
                # Case 2: Node 'i' is a descendant of node 'j'.
                # Similar to Case 1, but the roles of i and j are swapped.
                elif is_descendant_of(j, i):
                    xor_comp1 = subtree_xor_sums[i]
                    xor_comp2 = subtree_xor_sums[j] ^ subtree_xor_sums[i]
                    xor_comp3 = total_tree_xor_val ^ subtree_xor_sums[j]
                # Case 3: Nodes 'i' and 'j' are in different branches (neither is a descendant of the other).
                # The three components' XORs would be:
                # 1. Subtree rooted at i.
                # 2. Subtree rooted at j.
                # 3. The rest of the tree (total XOR minus both subtrees).
                else:
                    xor_comp1 = subtree_xor_sums[i]
                    xor_comp2 = subtree_xor_sums[j]
                    xor_comp3 = total_tree_xor_val ^ subtree_xor_sums[i] ^ subtree_xor_sums[j]

                # Find the minimum and maximum XOR values among the three components.
                current_min_xor = min(xor_comp1, xor_comp2, xor_comp3)
                current_max_xor = max(xor_comp1, xor_comp2, xor_comp3)
                
                # Update the overall minimum score found so far.
                min_possible_score = min(min_possible_score, current_max_xor - current_min_xor)
        
        return min_possible_score

