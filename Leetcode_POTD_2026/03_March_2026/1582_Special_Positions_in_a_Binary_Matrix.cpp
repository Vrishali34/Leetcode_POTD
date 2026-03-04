class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int r_len = mat.size(), c_len = mat[0].size(), solo_hits = 0;
        vector<int> r_tally(r_len, 0), c_tally(c_len, 0);
        for (int i = 0; i < r_len; ++i)
            for (int j = 0; j < c_len; ++j)
                if (mat[i][j]) { r_tally[i]++; c_tally[j]++; }
        for (int i = 0; i < r_len; ++i)
            for (int j = 0; j < c_len; ++j)
                if (mat[i][j] && r_tally[i] == 1 && c_tally[j] == 1) solo_hits++;
        return solo_hits;
    }
};
