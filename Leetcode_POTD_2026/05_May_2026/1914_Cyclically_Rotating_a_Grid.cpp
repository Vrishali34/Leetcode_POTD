class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m_rows = grid.size(), n_cols = grid[0].size();
        int rings_count = min(m_rows, n_cols) / 2;
        for (int ring_idx = 0; ring_idx < rings_count; ++ring_idx) {
            vector<int> ring_vals;
            for (int j = ring_idx; j < n_cols - ring_idx - 1; ++j) ring_vals.push_back(grid[ring_idx][j]);
            for (int i = ring_idx; i < m_rows - ring_idx - 1; ++i) ring_vals.push_back(grid[i][n_cols - ring_idx - 1]);
            for (int j = n_cols - ring_idx - 1; j > ring_idx; --j) ring_vals.push_back(grid[m_rows - ring_idx - 1][j]);
            for (int i = m_rows - ring_idx - 1; i > ring_idx; --i) ring_vals.push_back(grid[i][ring_idx]);
            
            int ring_size = ring_vals.size();
            int shift_val = k % ring_size;
            int pos_ptr = 0;
            for (int j = ring_idx; j < n_cols - ring_idx - 1; ++j) grid[ring_idx][j] = ring_vals[(pos_ptr++ + shift_val) % ring_size];
            for (int i = ring_idx; i < m_rows - ring_idx - 1; ++i) grid[i][n_cols - ring_idx - 1] = ring_vals[(pos_ptr++ + shift_val) % ring_size];
            for (int j = n_cols - ring_idx - 1; j > ring_idx; --j) grid[m_rows - ring_idx - 1][j] = ring_vals[(pos_ptr++ + shift_val) % ring_size];
            for (int i = m_rows - ring_idx - 1; i > ring_idx; --i) grid[i][ring_idx] = ring_vals[(pos_ptr++ + shift_val) % ring_size];
        }
        return grid;
    }
};
