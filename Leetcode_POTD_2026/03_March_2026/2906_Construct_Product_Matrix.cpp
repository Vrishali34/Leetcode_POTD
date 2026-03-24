class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n_rows = grid.size(), m_cols = grid[0].size();
        vector<vector<int>> prod_mat(n_rows, vector<int>(m_cols));
        long long curr_mul = 1;
        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < m_cols; ++j) {
                prod_mat[i][j] = curr_mul;
                curr_mul = (curr_mul * (grid[i][j] % 12345)) % 12345;
            }
        }
        curr_mul = 1;
        for (int i = n_rows - 1; i >= 0; --i) {
            for (int j = m_cols - 1; j >= 0; --j) {
                prod_mat[i][j] = (prod_mat[i][j] * curr_mul) % 12345;
                curr_mul = (curr_mul * (grid[i][j] % 12345)) % 12345;
            }
        }
        return prod_mat;
    }
};
