class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int total_nodes = edges.size() + 1;
        vector<vector<int>> adj_list(total_nodes + 1);
        for (const auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        vector<int> node_depth(total_nodes + 1, -1);
        vector<int> bfs_queue;
        bfs_queue.push_back(1);
        node_depth[1] = 0;
        int max_depth = 0;
        size_t head = 0;
        while (head < bfs_queue.size()) {
            int curr_node = bfs_queue[head++];
            for (int neighbor_node : adj_list[curr_node]) {
                if (node_depth[neighbor_node] == -1) {
                    node_depth[neighbor_node] = node_depth[curr_node] + 1;
                    if (node_depth[neighbor_node] > max_depth) {
                        max_depth = node_depth[neighbor_node];
                    }
                    bfs_queue.push_back(neighbor_node);
                }
            }
        }
        long long ways_count = 1;
        long long base_val = 2;
        int exp_val = max_depth - 1;
        long long mod_val = 1e9 + 7;
        while (exp_val > 0) {
            if (exp_val & 1) ways_count = (ways_count * base_val) % mod_val;
            base_val = (base_val * base_val) % mod_val;
            exp_val >>= 1;
        }
        return ways_count;
    }
};
