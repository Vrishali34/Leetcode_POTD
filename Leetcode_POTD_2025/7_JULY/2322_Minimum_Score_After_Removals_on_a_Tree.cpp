#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::vector<std::vector<int>> adj_list;
    std::vector<int> subtree_xor_sums;
    std::vector<int> entry_times, exit_times;
    int dfs_time_counter;

    void calculate_subtree_data(int current_node, int parent_node, const std::vector<int>& node_values) {
        entry_times[current_node] = dfs_time_counter++;
        subtree_xor_sums[current_node] = node_values[current_node];
        for (int neighbor : adj_list[current_node]) {
            if (neighbor == parent_node) continue;
            calculate_subtree_data(neighbor, current_node, node_values);
            subtree_xor_sums[current_node] ^= subtree_xor_sums[neighbor];
        }
        exit_times[current_node] = dfs_time_counter++;
    }

    bool is_descendant_of(int potential_ancestor, int potential_descendant) {
        return entry_times[potential_ancestor] <= entry_times[potential_descendant] &&
               exit_times[potential_ancestor] >= exit_times[potential_descendant];
    }

    int minimumScore(std::vector<int>& nums, std::vector<std::vector<int>>& edges) {
        int num_nodes = nums.size();
        adj_list.assign(num_nodes, std::vector<int>());
        subtree_xor_sums.assign(num_nodes, 0);
        entry_times.assign(num_nodes, 0);
        exit_times.assign(num_nodes, 0);
        dfs_time_counter = 0;

        for (const auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        calculate_subtree_data(0, -1, nums);

        int total_tree_xor_val = subtree_xor_sums[0];
        int min_possible_score = INT_MAX;

        for (int i = 1; i < num_nodes; ++i) {
            for (int j = i + 1; j < num_nodes; ++j) {
                int xor_comp1, xor_comp2, xor_comp3;

                if (is_descendant_of(i, j)) {
                    xor_comp1 = subtree_xor_sums[j];
                    xor_comp2 = subtree_xor_sums[i] ^ subtree_xor_sums[j];
                    xor_comp3 = total_tree_xor_val ^ subtree_xor_sums[i];
                } else if (is_descendant_of(j, i)) {
                    xor_comp1 = subtree_xor_sums[i];
                    xor_comp2 = subtree_xor_sums[j] ^ subtree_xor_sums[i];
                    xor_comp3 = total_tree_xor_val ^ subtree_xor_sums[j];
                } else {
                    xor_comp1 = subtree_xor_sums[i];
                    xor_comp2 = subtree_xor_sums[j];
                    xor_comp3 = total_tree_xor_val ^ subtree_xor_sums[i] ^ subtree_xor_sums[j];
                }

                int current_min_xor = std::min({xor_comp1, xor_comp2, xor_comp3});
                int current_max_xor = std::max({xor_comp1, xor_comp2, xor_comp3});
                min_possible_score = std::min(min_possible_score, current_max_xor - current_min_xor);
            }
        }
        return min_possible_score;
    }
};
