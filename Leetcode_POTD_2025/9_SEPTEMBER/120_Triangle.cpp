class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& pyramid_data) {
        int n_rows = pyramid_data.size();
        std::vector<int> path_sums = pyramid_data.back();
        for (int row_i = n_rows - 2; row_i >= 0; --row_i) {
            for (int col_j = 0; col_j <= row_i; ++col_j) {
                path_sums[col_j] = pyramid_data[row_i][col_j] + std::min(path_sums[col_j], path_sums[col_j + 1]);
            }
        }
        return path_sums[0];
    }
};
