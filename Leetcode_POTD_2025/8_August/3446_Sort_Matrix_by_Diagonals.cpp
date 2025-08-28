class Solution {
public:
    std::vector<std::vector<int>> sortMatrix(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::map<int, std::vector<int>> bottom_left, top_right;

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (row >= col) {
                    bottom_left[row - col].push_back(grid[row][col]);
                } else {
                    top_right[row - col].push_back(grid[row][col]);
                }
            }
        }

        for (auto const& [key, val] : bottom_left) {
            std::sort(bottom_left[key].rbegin(), bottom_left[key].rend());
        }

        for (auto const& [key, val] : top_right) {
            std::sort(top_right[key].begin(), top_right[key].end());
        }

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (row >= col) {
                    grid[row][col] = bottom_left[row - col].back();
                    bottom_left[row - col].pop_back();
                } else {
                    grid[row][col] = top_right[row - col].front();
                    top_right[row - col].erase(top_right[row - col].begin());
                }
            }
        }
        return grid;
    }
};
