#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

class Solution {
public:
    std::pair<int, int> computeBipartitionCounts(int num_nodes, const std::vector<std::vector<int>>& adj, std::vector<int>& node_depth_parities) {
        std::fill(node_depth_parities.begin(), node_depth_parities.end(), -1);
        std::queue<std::pair<int, int>> q;

        q.push({0, 0});
        node_depth_parities[0] = 0;

        int even_depth_count = 0;
        int odd_depth_count = 0;

        while (!q.empty()) {
            std::pair<int, int> current = q.front();
            q.pop();

            int u = current.first;
            int u_parity = current.second;

            if (u_parity == 0) {
                even_depth_count++;
            } else {
                odd_depth_count++;
            }

            for (int v : adj[u]) {
                if (node_depth_parities[v] == -1) {
                    node_depth_parities[v] = 1 - u_parity;
                    q.push({v, 1 - u_parity});
                }
            }
        }
        return {even_depth_count, odd_depth_count};
    }

    std::vector<int> maxTargetNodes(std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        std::vector<std::vector<int>> adj1(n);
        for (const auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }

        std::vector<std::vector<int>> adj2(m);
        for (const auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        std::vector<int> node_parities_T1(n);
        std::pair<int, int> counts_T1_from_root0 = computeBipartitionCounts(n, adj1, node_parities_T1);
        int even_partition_size_T1 = counts_T1_from_root0.first;
        int odd_partition_size_T1 = counts_T1_from_root0.second;

        std::vector<int> node_parities_T2(m);
        std::pair<int, int> counts_T2_from_root0 = computeBipartitionCounts(m, adj2, node_parities_T2);
        int even_partition_size_T2 = counts_T2_from_root0.first;
        int odd_partition_size_T2 = counts_T2_from_root0.second;

        int max_odd_dist_nodes_T2 = std::max(even_partition_size_T2, odd_partition_size_T2);

        std::vector<int> answer(n);
        for (int i = 0; i < n; ++i) {
            int nodes_even_dist_from_i_in_T1;
            
            if (node_parities_T1[i] == 0) { 
                nodes_even_dist_from_i_in_T1 = even_partition_size_T1;
            } else { 
                nodes_even_dist_from_i_in_T1 = odd_partition_size_T1;
            }
            
            answer[i] = nodes_even_dist_from_i_in_T1 + max_odd_dist_nodes_T2;
        }

        return answer;
    }
};
