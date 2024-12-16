class Solution {
public:
    vector<int> getFinalState(vector<int>& e, int q, int r) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> z;
        for (int o = 0; o < e.size(); o++) z.push({e[o], o});
        while (q--) {
            auto b = z.top();
            z.pop();
            e[b.second] = r * b.first;
            z.push({e[b.second], b.second});
        }
        return e;
    }
};
