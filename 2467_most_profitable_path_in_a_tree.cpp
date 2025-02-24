class Solution {
public:
    unordered_map<int, vector<int>> e;
    unordered_map<int, int> bMap;
    int maxGain = INT_MIN;

    bool traceBob(int n, int t, vector<bool>& v) {
        v[n] = true;
        bMap[n] = t;
        if (n == 0) return true;
        for (int nb : e[n]) if (!v[nb] && traceBob(nb, t + 1, v)) return true;
        bMap.erase(n);
        return false;
    }

    void traceAlice(int n, int t, int gain, vector<bool>& v, vector<int>& amt) {
        v[n] = true;
        gain += (!bMap.count(n) || t < bMap[n]) ? amt[n] : (t == bMap[n] ? amt[n] / 2 : 0);
        if (e[n].size() == 1 && n != 0) maxGain = max(maxGain, gain);
        for (int nb : e[n]) if (!v[nb]) traceAlice(nb, t + 1, gain, v, amt);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        for (auto& ed : edges) e[ed[0]].push_back(ed[1]), e[ed[1]].push_back(ed[0]);
        vector<bool> v(amount.size(), false);
        traceBob(bob, 0, v), v.assign(amount.size(), false);
        traceAlice(0, 0, 0, v, amount);
        return maxGain;
    }
};
