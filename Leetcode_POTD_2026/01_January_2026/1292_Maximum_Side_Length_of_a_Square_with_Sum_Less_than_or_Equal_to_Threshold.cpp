class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size(), cols = mat[0].size(), max_edge = 0;
        vector<vector<int>> area_sum(rows + 1, vector<int>(cols + 1, 0));
        for (int r = 1; r <= rows; ++r) {
            for (int c = 1; c <= cols; ++c) {
                area_sum[r][c] = mat[r-1][c-1] + area_sum[r-1][c] + area_sum[r][c-1] - area_sum[r-1][c-1];
                if (max_edge + 1 <= r && max_edge + 1 <= c) {
                    int curr_sum = area_sum[r][c] - area_sum[r - max_edge - 1][c] - area_sum[r][c - max_edge - 1] + area_sum[r - max_edge - 1][c - max_edge - 1];
                    if (curr_sum <= threshold) max_edge++;
                }
            }
        }
        return max_edge;
    }
};
