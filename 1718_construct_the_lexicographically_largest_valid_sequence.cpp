class Solution {
public:
    vector<int> z;
    vector<bool> y;
    bool f(int x, int n) {
        if (x == z.size()) return true;
        if (z[x]) return f(x + 1, n);
        for (int v = n; v; v--) {
            if (y[v]) continue;
            int j = v == 1 ? x : x + v;
            if (j >= z.size() || z[j]) continue;
            z[x] = z[j] = v;
            y[v] = true;
            if (f(x + 1, n)) return true;
            z[x] = z[j] = 0;
            y[v] = false;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        z = vector<int>(2 * n - 1);
        y = vector<bool>(n + 1);
        f(0, n);
        return z;
    }
};
