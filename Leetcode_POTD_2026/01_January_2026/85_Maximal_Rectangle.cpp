class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int col_sz = matrix[0].size(), max_rect = 0;
        vector<int> alt_depth(col_sz + 1, 0);
        for (const auto& row_vec : matrix) {
            stack<int> idx_stack;
            for (int j = 0; j <= col_sz; ++j) {
                if (j < col_sz) alt_depth[j] = (row_vec[j] == '1') ? alt_depth[j] + 1 : 0;
                while (!idx_stack.empty() && alt_depth[idx_stack.top()] >= alt_depth[j]) {
                    int h_val = alt_depth[idx_stack.top()];
                    idx_stack.pop();
                    int w_val = idx_stack.empty() ? j : j - idx_stack.top() - 1;
                    max_rect = max(max_rect, h_val * w_val);
                }
                idx_stack.push(j);
            }
        }
        return max_rect;
    }
};
