class Solution {
public:
    long long mostPoints(vector<vector<int>>& k) {
        int l = k.size();
        vector<long long> m(l + 1);
        for (int n = l - 1; n >= 0; --n)
            m[n] = max(k[n][0] + ((n + k[n][1] + 1 < l) ? m[n + k[n][1] + 1] : 0), m[n + 1]);
        return m[0];
    }
};
