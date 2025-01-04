class Solution {
public:
    int countPalindromicSubsequence(string y) {
        int z = y.size(), x = 0;
        vector<int> p(26, -1), q(26, z);
        for (int i = 0; i < z; ++i) {
            if (p[y[i] - 'a'] == -1) p[y[i] - 'a'] = i;
            q[y[i] - 'a'] = i;
        }
        for (int o = 0; o < 26; ++o) {
            if (p[o] != -1 && q[o] != z) {
                unordered_set<int> r;
                for (int t = p[o] + 1; t < q[o]; ++t) r.insert(y[t]);
                x += r.size();
            }
        }
        return x;
    }
};
