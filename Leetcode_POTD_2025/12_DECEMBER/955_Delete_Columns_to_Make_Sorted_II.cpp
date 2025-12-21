class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n_rows = strs.size(), n_cols = strs[0].size(), cut_count = 0;
        vector<bool> is_sorted(n_rows, false);
        for (int c = 0; c < n_cols; ++c) {
            int r = 1;
            for (; r < n_rows; ++r) {
                if (!is_sorted[r] && strs[r][c] < strs[r-1][c]) {
                    cut_count++;
                    break;
                }
            }
            if (r == n_rows) {
                for (int i = 1; i < n_rows; ++i) {
                    if (strs[i][c] > strs[i-1][c]) is_sorted[i] = true;
                }
            }
        }
        return cut_count;
    }
};
