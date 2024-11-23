class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& b) {
        int q = b.size(), s = b[0].size();
        vector<vector<char>> t(s, vector<char>(q));
        for (int g = 0; g < q; g++) {
            int h = s - 1;
            for (int k = s - 1; k >= 0; k--) {
                if (b[g][k] == '*') h = k - 1;
                else if (b[g][k] == '#') b[g][k] = '.', b[g][h--] = '#';
            }
        }
        for (int g = 0; g < q; g++) for (int k = 0; k < s; k++) t[k][q - g - 1] = b[g][k];
        return t;
    }
};
