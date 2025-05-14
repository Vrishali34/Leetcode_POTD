class Solution {
public:
    int lengthAfterTransformations(string x, int y, vector<int>& z) {
        int d = 26, m = 1e9+7;
        vector<vector<long long>> a(d, vector<long long>(d)), r(d, vector<long long>(d));
        for(int i = 0; i < d; ++i) r[i][i] = 1;
        for(int i = 0; i < d; ++i) for(int j = 1; j <= z[i]; ++j) a[i][(i + j) % d]++;
        while(y) {
            if (y & 1) {
                vector<vector<long long>> t(d, vector<long long>(d));
                for(int i = 0; i < d; ++i) for(int j = 0; j < d; ++j)
                    for(int k = 0; k < d; ++k) t[i][j] = (t[i][j] + r[i][k] * a[k][j]) % m;
                r = t;
            }
            vector<vector<long long>> t(d, vector<long long>(d));
            for(int i = 0; i < d; ++i) for(int j = 0; j < d; ++j)
                for(int k = 0; k < d; ++k) t[i][j] = (t[i][j] + a[i][k] * a[k][j]) % m;
            a = t;
            y >>= 1;
        }
        vector<long long> cnt(d);
        for(char c : x) cnt[c - 'a']++;
        long long ans = 0;
        for(int i = 0; i < d; ++i) {
            long long tmp = 0;
            for(int j = 0; j < d; ++j) tmp = (tmp + r[i][j]) % m;
            ans = (ans + cnt[i] * tmp) % m;
        }
        return ans;
    }
};
