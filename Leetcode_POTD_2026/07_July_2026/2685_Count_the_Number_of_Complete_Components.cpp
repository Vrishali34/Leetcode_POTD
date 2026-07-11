class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> node_mesh(n);
        for (const auto& bond : edges) {
            node_mesh[bond[0]].push_back(bond[1]);
            node_mesh[bond[1]].push_back(bond[0]);
        }
        vector<bool> seen_node(n, false);
        int valid_cliques = 0;
        for (int v_idx = 0; v_idx < n; ++v_idx) {
            if (seen_node[v_idx]) continue;
            int total_v = 0, total_e = 0;
            vector<int> pipeline = {v_idx};
            seen_node[v_idx] = true;
            while (!pipeline.empty()) {
                int curr_v = pipeline.back();
                pipeline.pop_back();
                total_v++;
                total_e += node_mesh[curr_v].size();
                for (int nbr_v : node_mesh[curr_v]) {
                    if (!seen_node[nbr_v]) {
                        seen_node[nbr_v] = true;
                        pipeline.push_back(nbr_v);
                    }
                }
            }
            if (total_e == total_v * (total_v - 1)) valid_cliques++;
        }
        return valid_cliques;
    }
};
