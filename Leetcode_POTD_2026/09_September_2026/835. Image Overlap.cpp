class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int grid_len = img1.size();
        vector<pair<int,int>> pts_one, pts_two;

        for (int row_idx = 0; row_idx < grid_len; row_idx++)
            for (int col_idx = 0; col_idx < grid_len; col_idx++) {
                if (img1[row_idx][col_idx]) pts_one.push_back({row_idx, col_idx});
                if (img2[row_idx][col_idx]) pts_two.push_back({row_idx, col_idx});
            }

        unordered_map<int, int> shift_freq;
        int best_overlap = 0;

        for (auto& pt_a : pts_one) {
            for (auto& pt_b : pts_two) {
                int delta_row = pt_a.first - pt_b.first;
                int delta_col = pt_a.second - pt_b.second;
                int shift_key = (delta_row + 60) * 200 + (delta_col + 60);
                best_overlap = max(best_overlap, ++shift_freq[shift_key]);
            }
        }

        return best_overlap;
    }
};
