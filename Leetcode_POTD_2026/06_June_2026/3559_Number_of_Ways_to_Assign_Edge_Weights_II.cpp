class Solution {
    static constexpr int MODULO_BASE = 1e9 + 7;
    static constexpr int MAX_POWER_LOG = 18;
    vector<vector<int>> network_map;
    vector<vector<int>> jump_ancestors;
    vector<int> node_depths;

    void trace_tree_depths(int current_node, int parent_node) {
        jump_ancestors[0][current_node] = parent_node;
        for (int neighbor_node : network_map[current_node]) {
            if (neighbor_node != parent_node) {
                node_depths[neighbor_node] = node_depths[current_node] + 1;
                trace_tree_depths(neighbor_node, current_node);
            }
        }
    }

    int fetch_common_ancestor(int active_node_u, int active_node_v) {
        if (node_depths[active_node_u] < node_depths[active_node_v]) swap(active_node_u, active_node_v);
        for (int bit_idx = MAX_POWER_LOG - 1; bit_idx >= 0; bit_idx--) {
            if (jump_ancestors[bit_idx][active_node_u] != -1 && node_depths[jump_ancestors[bit_idx][active_node_u]] >= node_depths[active_node_v]) {
                active_node_u = jump_ancestors[bit_idx][active_node_u];
            }
        }
        if (active_node_u == active_node_v) return active_node_u;
        for (int bit_idx = MAX_POWER_LOG - 1; bit_idx >= 0; bit_idx--) {
            if (jump_ancestors[bit_idx][active_node_u] != jump_ancestors[bit_idx][active_node_v]) {
                active_node_u = jump_ancestors[bit_idx][active_node_u];
                active_node_v = jump_ancestors[bit_idx][active_node_v];
            }
        }
        return jump_ancestors[0][active_node_u];
    }

    long long compute_modular_exponent(long long base_val, long long exp_val) {
        long long final_product = 1;
        while (exp_val > 0) {
            if (exp_val & 1) final_product = (final_product * base_val) % MODULO_BASE;
            base_val = (base_val * base_val) % MODULO_BASE;
            exp_val >>= 1;
        }
        return final_product;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int total_nodes = edges.size() + 1;
        network_map.resize(total_nodes + 1);
        node_depths.assign(total_nodes + 1, 0);
        jump_ancestors.assign(MAX_POWER_LOG, vector<int>(total_nodes + 1, -1));
        for (const auto& edge_pair : edges) {
            network_map[edge_pair[0]].push_back(edge_pair[1]);
            network_map[edge_pair[1]].push_back(edge_pair[0]);
        }
        trace_tree_depths(1, -1);
        for (int bit_idx = 1; bit_idx < MAX_POWER_LOG; bit_idx++) {
            for (int node_idx = 1; node_idx <= total_nodes; node_idx++) {
                if (jump_ancestors[bit_idx - 1][node_idx] != -1) {
                    jump_ancestors[bit_idx][node_idx] = jump_ancestors[bit_idx - 1][jump_ancestors[bit_idx - 1][node_idx]];
                }
            }
        }
        vector<int> target_results;
        target_results.reserve(queries.size());
        for (const auto& query_pair : queries) {
            int shared_ancestor = fetch_common_ancestor(query_pair[0], query_pair[1]);
            int complete_path_span = node_depths[query_pair[0]] + node_depths[query_pair[1]] - 2 * node_depths[shared_ancestor];
            target_results.push_back(complete_path_span ? compute_modular_exponent(2, complete_path_span - 1) : 0);
        }
        return target_results;
    }
};
