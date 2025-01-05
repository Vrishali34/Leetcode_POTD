class Solution {
public:
    string shiftingLetters(string z, vector<vector<int>>& p) {
        int x = z.size();
        vector<int> f(x + 1);
        for (auto& r : p) f[r[0]] += r[2] == 1 ? 1 : -1, f[r[1] + 1] -= r[2] == 1 ? 1 : -1;
        for (int i = 0, q = 0; i < x; ++i) f[i] = (q += f[i]) % 26;
        for (int i = 0; i < x; ++i) z[i] = 'a' + (z[i] - 'a' + (f[i] + 26) % 26) % 26;
        return z;
    }
};
