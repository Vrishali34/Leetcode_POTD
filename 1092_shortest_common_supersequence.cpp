class Solution { 
public:
    string shortestCommonSupersequence(string x, string y) {
        int a = x.size(), b = y.size();
        vector<vector<int>> p(a + 1, vector<int>(b + 1, 0));
        for (int i = 0; i <= a; i++) for (int j = 0; j <= b; j++)
            if (!i || !j) p[i][j] = i + j;
            else p[i][j] = x[i - 1] == y[j - 1] ? 1 + p[i - 1][j - 1] : 1 + min(p[i - 1][j], p[i][j - 1]);
        string r;
        int i = a, j = b;
        while (i || j) {
            if (i && j && x[i - 1] == y[j - 1]) r += x[--i], j--;
            else if (i && (!j || p[i - 1][j] < p[i][j - 1])) r += x[--i];
            else r += y[--j];
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
