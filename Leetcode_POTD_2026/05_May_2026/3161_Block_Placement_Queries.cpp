class Solution {
    int st[200005];
    void node_upd(int i, int l, int r, int p, int v) {
        if (l == r) {
            st[i] = v;
            return;
        }
        int m = (l + r) >> 1;
        if (p <= m) node_upd(i << 1, l, m, p, v);
        else node_upd((i << 1) | 1, m + 1, r, p, v);
        st[i] = max(st[i << 1], st[(i << 1) | 1]);
    }
    int range_max(int i, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (ql <= l && r <= qr) return st[i];
        int m = (l + r) >> 1;
        return max(range_max(i << 1, l, m, ql, qr),
                   range_max((i << 1) | 1, m + 1, r, ql, qr));
    }
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 50002;
        memset(st, 0, sizeof(st));
        set<int> obs_set;
        obs_set.insert(0);
        vector<bool> ans;
        for (const auto& cur_q : queries) {
            if (cur_q[0] == 1) {
                int x = cur_q[1];
                auto R = obs_set.lower_bound(x);
                auto L = prev(R);
                node_upd(1, 0, max_x, x, x - *L);
                if (R != obs_set.end()) {
                    node_upd(1, 0, max_x, *R, *R - x);
                }
                obs_set.insert(x);
            } else {
                int x = cur_q[1], sz = cur_q[2];
                int gap = range_max(1, 0, max_x, 0, x);
                auto L = prev(obs_set.upper_bound(x));
                gap = max(gap, x - *L);
                ans.push_back(gap >= sz);
            }
        }
        return ans;
    }
};
