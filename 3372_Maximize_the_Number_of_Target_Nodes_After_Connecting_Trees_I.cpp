#include <vector>
#include <queue>
#include <algorithm>

int countNodesWithinDistance(int start_node, int max_allowed_dist, int total_nodes, const std::vector<std::vector<int>>& adj_list) {
    std::queue<std::pair<int, int>> q_frontier;
    std::vector<int> current_node_distances(total_nodes, -1);
    int reachable_count = 0;

    q_frontier.push({start_node, 0});
    current_node_distances[start_node] = 0;

    while (!q_frontier.empty()) {
        std::pair<int, int> current_process = q_frontier.front();
        q_frontier.pop();
        int u_id = current_process.first;
        int d_val = current_process.second;

        if (d_val > max_allowed_dist) { 
            continue; 
        }
        reachable_count++;

        for (int v_neighbor_id : adj_list[u_id]) {
            if (current_node_distances[v_neighbor_id] == -1) {
                current_node_distances[v_neighbor_id] = d_val + 1;
                q_frontier.push({v_neighbor_id, d_val + 1});
            }
        }
    }
    return reachable_count;
}

class Solution {
public:
    std::vector<int> maxTargetNodes(std::vector<std::vector<int>>& graph_alpha_edges, std::vector<std::vector<int>>& graph_beta_edges, int k_limit) {
        int alpha_size = graph_alpha_edges.size() + 1;
        int beta_size = graph_beta_edges.size() + 1;

        std::vector<std::vector<int>> adj_alpha(alpha_size);
        for (const auto& edge_def : graph_alpha_edges) {
            adj_alpha[edge_def[0]].push_back(edge_def[1]);
            adj_alpha[edge_def[1]].push_back(edge_def[0]);
        }

        std::vector<std::vector<int>> adj_beta(beta_size);
        for (const auto& edge_def : graph_beta_edges) {
            adj_beta[edge_def[0]].push_back(edge_def[1]);
            adj_beta[edge_def[1]].push_back(edge_def[0]);
        }

        std::vector<int> alpha_reachable_values(alpha_size);
        for (int i_idx = 0; i_idx < alpha_size; ++i_idx) {
            alpha_reachable_values[i_idx] = countNodesWithinDistance(i_idx, k_limit, alpha_size, adj_alpha);
        }

        int max_beta_reachable = 0;
        for (int j_idx = 0; j_idx < beta_size; ++j_idx) {
            max_beta_reachable = std::max(max_beta_reachable, countNodesWithinDistance(j_idx, k_limit - 1, beta_size, adj_beta));
        }

        std::vector<int> final_computed_results(alpha_size);
        for (int i_idx = 0; i_idx < alpha_size; ++i_idx) {
            final_computed_results[i_idx] = alpha_reachable_values[i_idx] + max_beta_reachable;
        }

        return final_computed_results;
    }
};
