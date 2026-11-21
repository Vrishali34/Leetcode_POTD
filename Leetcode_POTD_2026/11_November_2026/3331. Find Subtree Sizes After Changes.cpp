class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> kids(n);
        for (int i = 1; i < n; i++) kids[parent[i]].push_back(i);
        vector<int> sub_size(n, 1), new_par(n, -1), prev_seen(n, -1), next_kid(n, 0), last_seen(26, -1), stk{0};
        last_seen[s[0] - 'a'] = 0;
        while (!stk.empty()) {
            int node = stk.back();
            if (next_kid[node] < kids[node].size()) {
                int kid = kids[node][next_kid[node]++], ch = s[kid] - 'a';
                new_par[kid] = last_seen[ch] < 0 ? node : last_seen[ch];
                prev_seen[kid] = last_seen[ch];
                last_seen[ch] = kid;
                stk.push_back(kid);
            } else {
                last_seen[s[node] - 'a'] = prev_seen[node];
                if (node) sub_size[new_par[node]] += sub_size[node];
                stk.pop_back();
            }
        }
        return sub_size;
    }
};
