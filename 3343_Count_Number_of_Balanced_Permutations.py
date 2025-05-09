// Version 1
class Solution {
public:
    int countBalancedPermutations(string z) {
        int n = z.size(), s = 0, p[10] = {}, q[11] = {};
        for (char c : z) p[c - '0']++, s += c - '0';
        if (s & 1) return 0;
        int m = (n + 1) / 2, t = s / 2;
        for (int i = 9; i >= 0; --i) q[i] = q[i + 1] + p[i];
        vector<vector<long long>> C(m + 1, vector<long long>(m + 1));
        for (int i = 0; i <= m; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; ++j)
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
        }
        long long M[10][1001][501];
        memset(M, -1, sizeof M);
        function<long long(int, int, int)> f = [&](int x, int y, int z) {
            if (z < 0 || q[x] < z || y > t) return 0LL;
            if (x > 9) return (y == t && z == 0) ? 1LL : 0LL;
            if (M[x][y][z] != -1) return M[x][y][z];
            int e = q[x] - z;
            long long r = 0;
            for (int k = max(0, p[x] - e); k <= min(p[x], z); ++k) {
                long long w = C[z][k] * C[e][p[x] - k] % 1000000007;
                r = (r + w * f(x + 1, y + k * x, z - k)) % 1000000007;
            }
            return M[x][y][z] = r;
        };
        return f(0, 0, m);
    }
};
