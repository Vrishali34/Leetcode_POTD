class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long mod = 1e9 + 7;
        vector<long long> known(n + 1, 0);
        long long share = 0;
        known[1] = 1;

        for (int i = 2; i <= n; ++i) {
            share = (share + known[max(0, i - delay)] - known[max(0, i - forget)] + mod) % mod;
            known[i] = share;
        }

        long long total = 0;
        for (int i = n; i > n - forget; --i) {
            total = (total + known[i]) % mod;
        }
        return total;
    }
};
