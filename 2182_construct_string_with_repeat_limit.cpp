class Solution {
public:
    string repeatLimitedString(string z, int r) {
        vector<int> a(26, 0);
        for (char x : z) a[x - 'a']++;
        priority_queue<pair<char, int>> q;
        for (int i = 0; i < 26; i++) if (a[i]) q.push({i + 'a', a[i]});
        string o;
        while (!q.empty()) {
            auto [x, y] = q.top(); q.pop();
            int u = min(r, y);
            o.append(u, x);
            if ((y -= u) && !q.empty()) {
                auto [v, w] = q.top(); q.pop();
                o.push_back(v);
                if (--w) q.push({v, w});
                q.push({x, y});
            }
        }
        return o;
    }
};
