class Solution {
public:
    int cqn(std::vector<std::vector<int>>& gx) {
        std::unordered_map<int, std::list<int>> t;
        std::vector<int> v(gx.size() + 1);
        for (auto& y : gx) {
            t[y[0]].push_back(y[1]);
            t[y[1]].push_back(y[0]);
            v[y[0]]++;
            v[y[1]]++;
        }
        std::queue<int> q;
        for (int i = 0; i < v.size(); i++) if (v[i] == 1) q.push(i);
        int s = gx.size() + 1, l = 0;
        while (s > 2) {
            int z = q.size(); s -= z; l++;
            while (z--) {
                int x = q.front(); q.pop();
                for (auto& j : t[x]) if (--v[j] == 1) q.push(j);
            }
        }
        return (s == 2) ? 2 * l + 1 : 2 * l;
    }
    int minimumDiameterAfterMerge(std::vector<std::vector<int>>& e1, std::vector<std::vector<int>>& e2) {
        int p = cqn(e1), q = cqn(e2);
        return std::max({p, q, (p + 1) / 2 + (q + 1) / 2 + 1});
    }
};
