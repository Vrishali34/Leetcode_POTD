class Solution {
public:
    vector<int> partitionLabels(string t) {
        int u[128] = {}, j = 0, d = 0;
        for (int i = 0; i < t.size(); i++) u[t[i]] = i;
        vector<int> r;
        for (int i = 0; i < t.size(); i++) {
            j = max(j, u[t[i]]);
            if (i == j) r.push_back(i - d + 1), d = i + 1;
        }
        return r;
    }
};
