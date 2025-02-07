class Solution {
public:
    vector<int> queryResults(int x, vector<vector<int>>& y) {
        int z = y.size();
        vector<int> w(z);
        unordered_map<int, int> a, b;
        for (int i = 0; i < z; i++) {
            int c = y[i][0], d = y[i][1];
            if (a.count(c)) {
                int e = a[c];
                if (--b[e] == 0) b.erase(e);
            }
            a[c] = d, b[d]++;
            w[i] = b.size();
        }
        return w;
    }
};
