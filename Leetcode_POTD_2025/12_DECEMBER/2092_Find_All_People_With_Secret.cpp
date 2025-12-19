class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int first_p) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        auto fetch_root = [&](auto self, int i) -> int {
            return parent[i] == i ? i : parent[i] = self(self, parent[i]);
        };
        auto unite_nodes = [&](int i, int j) {
            int r1 = fetch_root(fetch_root, i), r2 = fetch_root(fetch_root, j);
            if (r1 != r2) parent[r1] = r2;
        };

        unite_nodes(0, first_p);
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) { return a[2] < b[2]; });

        int m_idx = 0, m_len = meetings.size();
        while (m_idx < m_len) {
            int cur_t = meetings[m_idx][2];
            vector<int> pool;
            while (m_idx < m_len && meetings[m_idx][2] == cur_t) {
                int u = meetings[m_idx][0], v = meetings[m_idx][1];
                unite_nodes(u, v);
                pool.push_back(u);
                pool.push_back(v);
                m_idx++;
            }
            int root_zero = fetch_root(fetch_root, 0);
            for (int p : pool) {
                if (fetch_root(fetch_root, p) != root_zero) parent[p] = p;
            }
        }

        vector<int> informed;
        int target = fetch_root(fetch_root, 0);
        for (int i = 0; i < n; ++i) {
            if (fetch_root(fetch_root, i) == target) informed.push_back(i);
        }
        return informed;
    }
};
