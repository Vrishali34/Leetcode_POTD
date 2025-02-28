class Solution { 
public:
    string shortestCommonSupersequence(string a, string b) {
        int x = a.size(), y = b.size();
        vector<vector<int>> d(x + 1, vector<int>(y + 1, 0));
        for (int i = 1; i <= x; i++) for (int j = 1; j <= y; j++)
            d[i][j] = a[i - 1] == b[j - 1] ? d[i - 1][j - 1] + 1 : max(d[i - 1][j], d[i][j - 1]);
        string s;
        for (int i = x, j = y; i || j; )
            if (i && j && a[i - 1] == b[j - 1]) s += a[--i], j--;
            else if (j && (!i || d[i][j - 1] > d[i - 1][j])) s += b[--j];
            else s += a[--i];
        reverse(s.begin(), s.end());
        return s;
    }
};
