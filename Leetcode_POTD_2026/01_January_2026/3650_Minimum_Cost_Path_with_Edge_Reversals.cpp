class Solution {
public:
    long long minCost(int node_qty, vector<vector<int>>& edge_list) {
        vector<pair<int, int>> adj_map[node_qty];
        for (auto& e : edge_list) {
            adj_map[e[0]].push_back({e[1], e[2]});
            adj_map[e[1]].push_back({e[0], 2 * e[2]});
        }
        vector<long long> min_path(node_qty, -1);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> flux_pq;
        flux_pq.push({0, 0});
        while (!flux_pq.empty()) {
            auto [total_w, u_node] = flux_pq.top(); flux_pq.pop();
            if (min_path[u_node] != -1) continue;
            min_path[u_node] = total_w;
            if (u_node == node_qty - 1) return total_w;
            for (auto& [v_node, edge_w] : adj_map[u_node])
                if (min_path[v_node] == -1) flux_pq.push({total_w + edge_w, v_node});
        }
        return min_path[node_qty - 1];
    }
};
