class Solution {
    vector<int> node_link, node_rank;
    int find_origin(int i) {
        return node_link[i] == i ? i : node_link[i] = find_origin(node_link[i]);
    }
    bool join_nodes(int i, int j) {
        int r1 = find_origin(i), r2 = find_origin(j);
        if (r1 == r2) return false;
        if (node_rank[r1] < node_rank[r2]) node_link[r1] = r2;
        else if (node_rank[r1] > node_rank[r2]) node_link[r2] = r1;
        else { node_link[r2] = r1; node_rank[r1]++; }
        return true;
    }
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int low_val = 0, high_val = 200000, best_res = -1;
        while (low_val <= high_val) {
            int mid_val = low_val + (high_val - low_val) / 2;
            node_link.assign(n, 0); iota(node_link.begin(), node_link.end(), 0);
            node_rank.assign(n, 0);
            int boost_count = 0, link_count = 0;
            bool possible = true;
            for (auto& e : edges) {
                if (e[3] == 1) {
                    if (e[2] < mid_val || !join_nodes(e[0], e[1])) { possible = false; break; }
                    link_count++;
                }
            }
            if (possible) {
                for (auto& e : edges) if (e[3] == 0 && e[2] >= mid_val) if (join_nodes(e[0], e[1])) link_count++;
                for (auto& e : edges) {
                    if (e[3] == 0 && e[2] < mid_val && e[2] * 2 >= mid_val && boost_count < k) {
                        if (join_nodes(e[0], e[1])) { link_count++; boost_count++; }
                    }
                }
                if (link_count == n - 1) { best_res = mid_val; low_val = mid_val + 1; continue; }
            }
            high_val = mid_val - 1;
        }
        return best_res;
    }
};
