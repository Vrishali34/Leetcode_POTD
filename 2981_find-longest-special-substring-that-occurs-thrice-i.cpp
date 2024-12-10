class Solution {
public:
    int maximumLength(string u) {
        int j = u.size(), x = 1, k = j;
        if (!xy(u, j, x)) return -1;
        while (x + 1 < k) {
            int c = (x + k) / 2;
            if (xy(u, j, c)) x = c;
            else k = c;
        }
        return x;
    }
private:
    bool xy(const string& u, int j, int g) {
        vector<int> f(26, 0);
        int r = 0;
        for (int b = 0; b < j; b++) {
            while (u[r] != u[b]) r++;
            if (b - r + 1 >= g) f[u[b] - 'a']++;
            if (f[u[b] - 'a'] > 2) return true;
        }
        return false;
    }
};
