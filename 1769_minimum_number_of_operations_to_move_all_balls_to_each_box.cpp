class Solution {
public:
    vector<int> minOperations(string b) {
        int n = b.size(), c = 0, s = 0;
        vector<int> r(n, 0);
        for (int i = 0; i < n; ++i) r[i] += s, c += (b[i] == '1'), s += c;
        c = s = 0;
        for (int i = n - 1; i >= 0; --i) r[i] += s, c += (b[i] == '1'), s += c;
        return r;
    }
};
