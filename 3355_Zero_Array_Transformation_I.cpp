class Solution {
public:
    bool isZeroArray(vector<int>& q, vector<vector<int>>& r) {
        int n = q.size();
        map<int, int> m;
        for (auto& v : r) ++m[v[0]], --m[v[1]+1];
        int c = 0;
        for (int i = 0; i < n; ++i) {
            c += m[i];
            if (c < q[i]) return 0;
        }
        return 1;
    }
};
