class Solution {
public:
    int numSubmat(std::vector<std::vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        std::vector<std::vector<int>> heights(rows, std::vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    heights[i][j] = (i > 0) ? heights[i - 1][j] + 1 : 1;
                }
            }
        }
        int total = 0;
        for (int i = 0; i < rows; i++) {
            std::stack<std::vector<int>> st;
            int count = 0;
            for (int j = 0; j < cols; j++) {
                int h = heights[i][j];
                while (!st.empty() && st.top()[0] > h) {
                    st.pop();
                }
                int prev_count = st.empty() ? 0 : st.top()[1];
                int current_count = h * (j - (st.empty() ? -1 : st.top()[2])) + prev_count;
                total += current_count;
                st.push({h, current_count, j});
            }
        }
        return total;
    }
};
