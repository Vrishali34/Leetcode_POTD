class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int row_len = matrix.size(), col_len = matrix[0].size(), peak_area = 0;
        for (int r = 1; r < row_len; ++r) {
            for (int c = 0; c < col_len; ++c) {
                if (matrix[r][c]) matrix[r][c] += matrix[r-1][c];
            }
        }
        for (int r = 0; r < row_len; ++r) {
            vector<int> row_stats = matrix[r];
            sort(row_stats.rbegin(), row_stats.rend());
            for (int i = 0; i < col_len; ++i) {
                peak_area = max(peak_area, row_stats[i] * (i + 1));
            }
        }
        return peak_area;
    }
};
