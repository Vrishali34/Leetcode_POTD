class Solution {
public:
    int possibleStringCount(string x, int y) {
        vector<int> f;
        int64_t q = 1, m = 1e9 + 7;
        for (int i = 0; i < x.size();) {
            int j = i;
            while (++i < x.size() && x[i] == x[j]);
            if (i > j + 1) f.push_back(i - j - 1), q = q * (i - j) % m;
            y--;
        }
        if (y <= 0) return q;
        vector<int64_t> z(y, 0); z[0] = 1;
        for (int d : f) {
            for (int i = 1; i < y; i++) z[i] = (z[i] + z[i - 1]) % m;
            for (int i = y - 1; i > d; i--) z[i] = (z[i] - z[i - d - 1] + m) % m;
        }
        for (int i = 1; i < y; i++) z[i] = (z[i] + z[i - 1]) % m;
        return (q - z[y - 1] + m) % m;
    }
};
