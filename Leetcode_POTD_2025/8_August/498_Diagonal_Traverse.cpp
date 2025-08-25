class Solution {
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        int m = mat.size(), n = mat[0].size();
        std::vector<int> result_vec;
        int r = 0, c = 0;
        int up_down_toggle = 1;
        while (result_vec.size() < m * n) {
            result_vec.push_back(mat[r][c]);
            if (up_down_toggle == 1) {
                if (c == n - 1) { r++; up_down_toggle = -1; }
                else if (r == 0) { c++; up_down_toggle = -1; }
                else { r--; c++; }
            } else {
                if (r == m - 1) { c++; up_down_toggle = 1; }
                else if (c == 0) { r++; up_down_toggle = 1; }
                else { r++; c--; }
            }
        }
        return result_vec;
    }
};
