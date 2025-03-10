class Solution {
public:
    long long countOfSubstrings(string z, int y) {
        int x[2][128] = {}, q = 0, w = 0, e = 0, r = 0;
        long long t = 0;
        x[0]['a'] = x[0]['e'] = x[0]['i'] = x[0]['o'] = x[0]['u'] = 1;
        for (int u = 0; u < z.length(); u++) {
            char v = z[u];
            if (x[0][v]) w += ++x[1][v] == 1;
            else q++;
            while (q > y) { char p = z[r++]; if (x[0][p]) w -= --x[1][p] == 0; else q--; e = 0; }
            while (w == 5 && q == y && r < u && x[0][z[r]] && x[1][z[r]] > 1) e++, x[1][z[r++]]--;
            if (q == y && w == 5) t += 1 + e;
        }
        return t;
    }
};
