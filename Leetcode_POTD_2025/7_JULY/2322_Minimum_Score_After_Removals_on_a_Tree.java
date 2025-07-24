import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    private List<List<Integer>> adj_list;
    private int[] subtree_xor_sums;
    private int[] entry_times, exit_times;
    private int dfs_time_counter;

    // Helper method to perform DFS, calculate subtree XOR sums,
    // and record entry/exit times for descendant checks.
    private void calculate_subtree_data(int current_node, int parent_node, int[] node_values) {
        // Record the time when we first enter this node.
        entry_times[current_node] = dfs_time_counter++;
        // Initialize the subtree XOR sum with the current node's value.
        subtree_xor_sums[current_node] = node_values[current_node];

        // Traverse all neighbors.
        for (int neighbor : adj_list.get(current_node)) {
            // Skip the parent to avoid going back up the tree.
            if (neighbor == parent_node) {
                continue;
            }
            // Recursively call DFS for the child node.
            calculate_subtree_data(neighbor, current_node, node_values);
            // XOR the child's subtree sum into the current node's sum.
            subtree_xor_sums[current_node] ^= subtree_xor_sums[neighbor];
        }
        // Record the time when we exit this node (after visiting all its children).
        exit_times[current_node] = dfs_time_counter++;
    }

    // Helper method to check if 'potential_descendant' is a descendant of 'potential_ancestor'
    // using their entry and exit times from the DFS traversal.
    private boolean is_descendant_of(int potential_ancestor, int potential_descendant) {
        return entry_times[potential_ancestor] <= entry_times[potential_descendant] &&
               exit_times[potential_ancestor] >= exit_times[potential_descendant];
    }

    public int minimumScore(int[] nums, int[][] edges) {
        int num_nodes = nums.length;
        
        // Initialize adjacency list.
        adj_list = new ArrayList<>(num_nodes);
        for (int i = 0; i < num_nodes; i++) {
            adj_list.add(new ArrayList<>());
        }

        // Initialize arrays for subtree XOR sums and DFS timestamps.
        subtree_xor_sums = new int[num_nodes];
        entry_times = new int[num_nodes];
        exit_times = new int[num_nodes];
        dfs_time_counter = 0; // Reset DFS timer for each run.

        // Build the adjacency list from the given edges.
        for (int[] edge : edges) {
            adj_list.get(edge[0]).add(edge[1]);
            adj_list.get(edge[1]).add(edge[0]);
        }

        // Perform DFS starting from node 0 (root of the tree).
        calculate_subtree_data(0, -1, nums);

        // The total XOR sum of the entire tree is the subtree XOR sum of the root.
        int total_tree_xor_val = subtree_xor_sums[0];
        // Initialize minimum possible score to a very large value.
        int min_possible_score = Integer.MAX_VALUE;

        // Iterate through all possible pairs of nodes (i, j) to simulate removing edges.
        // We consider i and j as the roots of the subtrees that would be cut off.
        for (int i = 1; i < num_nodes; ++i) { // Start from 1 because edge removal means cutting a subtree, not the root itself.
            for (int j = i + 1; j < num_nodes; ++j) {
                int xor_comp1, xor_comp2, xor_comp3;

                // Case 1: Node 'j' is a descendant of node 'i'.
                // This means the edge leading to 'j' is inside the subtree rooted at 'i'.
                // If we cut edges (parent_of_i, i) and (parent_of_j, j):
                // Component 1: Subtree rooted at j.
                // Component 2: Subtree rooted at i, excluding subtree rooted at j.
                // Component 3: The rest of the tree (total XOR excluding subtree rooted at i).
                if (is_descendant_of(i, j)) {
                    xor_comp1 = subtree_xor_sums[j];
                    xor_comp2 = subtree_xor_sums[i] ^ subtree_xor_sums[j];
                    xor_comp3 = total_tree_xor_val ^ subtree_xor_sums[i];
                } 
                // Case 2: Node 'i' is a descendant of node 'j'.
                // Similar to Case 1, but roles of i and j are swapped.
                else if (is_descendant_of(j, i)) {
                    xor_comp1 = subtree_xor_sums[i];
                    xor_comp2 = subtree_xor_sums[j] ^ subtree_xor_sums[i];
                    xor_comp3 = total_tree_xor_val ^ subtree_xor_sums[j];
                } 
                // Case 3: Nodes 'i' and 'j' are in different subtrees (neither is a descendant of the other).
                // If we cut edges (parent_of_i, i) and (parent_of_j, j):
                // Component 1: Subtree rooted at i.
                // Component 2: Subtree rooted at j.
                // Component 3: The rest of the tree (total XOR excluding both subtrees).
                else {
                    xor_comp1 = subtree_xor_sums[i];
                    xor_comp2 = subtree_xor_sums[j];
                    xor_comp3 = total_tree_xor_val ^ subtree_xor_sums[i] ^ subtree_xor_sums[j];
                }

                // Find the minimum and maximum XOR values among the three components.
                int current_min_xor = Math.min(xor_comp1, Math.min(xor_comp2, xor_comp3));
                int current_max_xor = Math.max(xor_comp1, Math.max(xor_comp2, xor_comp3));
                
                // Update the overall minimum score.
                min_possible_score = Math.min(min_possible_score, current_max_xor - current_min_xor);
            }
        }
        return min_possible_score;
    }
}
