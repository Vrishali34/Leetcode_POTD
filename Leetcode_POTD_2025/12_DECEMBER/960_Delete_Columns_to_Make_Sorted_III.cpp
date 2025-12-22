class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int col_total = strs[0].size(), row_total = strs.size();
        vector<int> max_chain(col_total, 1);
        for (int curr_col = 1; curr_col < col_total; ++curr_col) {
            for (int prev_col = 0; prev_col < curr_col; ++prev_col) {
                bool fits_order = true;
                for (int r_idx = 0; r_idx < row_total; ++r_idx) {
                    if (strs[r_idx][prev_col] > strs[r_idx][curr_col]) {
                        fits_order = false;
                        break;
                    }
                }
                if (fits_order) max_chain[curr_col] = max(max_chain[curr_col], max_chain[prev_col] + 1);
            }
        }
        int top_seq = 0;
        for (int val : max_chain) top_seq = max(top_seq, val);
        return col_total - top_seq;
    }
};
