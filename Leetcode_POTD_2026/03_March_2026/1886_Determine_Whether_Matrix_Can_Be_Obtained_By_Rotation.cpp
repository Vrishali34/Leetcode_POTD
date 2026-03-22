class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n_len = mat.size();
        vector<bool> match_states(4, true);
        for (int i_idx = 0; i_idx < n_len; ++i_idx) {
            for (int j_idx = 0; j_idx < n_len; ++j_idx) {
                if (mat[i_idx][j_idx] != target[i_idx][j_idx]) match_states[0] = false;
                if (mat[i_idx][j_idx] != target[j_idx][n_len - 1 - i_idx]) match_states[1] = false;
                if (mat[i_idx][j_idx] != target[n_len - 1 - i_idx][n_len - 1 - j_idx]) match_states[2] = false;
                if (mat[i_idx][j_idx] != target[n_len - 1 - j_idx][i_idx]) match_states[3] = false;
            }
        }
        return match_states[0] || match_states[1] || match_states[2] || match_states[3];
    }
};
