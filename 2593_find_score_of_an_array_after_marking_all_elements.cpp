class Solution {
public:
    long long findScore(vector<int>& a) {
        long long s = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < a.size(); i++) pq.push({a[i], i});
        vector<bool> vis(a.size(), false);
        while (!pq.empty()) {
            auto [v, i] = pq.top(); pq.pop();
            if (vis[i]) continue;
            s += v;
            if (i > 0) vis[i - 1] = true;
            if (i < a.size() - 1) vis[i + 1] = true;
            vis[i] = true;
        }
        return s;
    }
};
