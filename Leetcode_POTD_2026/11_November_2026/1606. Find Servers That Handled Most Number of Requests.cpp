class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> freeSrv;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        vector<int> cnt(k), res;
        for (int s = 0; s < k; s++) freeSrv.insert(s);
        for (int i = 0; i < arrival.size(); i++) {
            for (; !busy.empty() && busy.top().first <= arrival[i]; busy.pop())
                freeSrv.insert(busy.top().second);
            if (freeSrv.empty()) continue;
            auto it = freeSrv.lower_bound(i % k);
            if (it == freeSrv.end()) it = freeSrv.begin();
            cnt[*it]++;
            busy.push({arrival[i] + (long long)load[i], *it});
            freeSrv.erase(it);
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        for (int s = 0; s < k; s++) if (cnt[s] == mx) res.push_back(s);
        return res;
    }
};
