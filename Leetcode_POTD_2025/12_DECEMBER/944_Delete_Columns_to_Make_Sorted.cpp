class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int drop_count = 0;
        int row_total = strs.size(), col_total = strs[0].size();
        for (int col_idx = 0; col_idx < col_total; ++col_idx) {
            for (int row_idx = 1; row_idx < row_total; ++row_idx) {
                if (strs[row_idx][col_idx] < strs[row_idx - 1][col_idx]) {
                    drop_count++;
                    break;
                }
            }
        }
        return drop_count;
    }
};
