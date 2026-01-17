class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottom_left, vector<vector<int>>& top_right) {
        long long max_side = 0;
        int rect_count = bottom_left.size();
        for (int i = 0; i < rect_count; ++i) {
            for (int j = i + 1; j < rect_count; ++j) {
                int low_x = max(bottom_left[i][0], bottom_left[j][0]);
                int low_y = max(bottom_left[i][1], bottom_left[j][1]);
                int high_x = min(top_right[i][0], top_right[j][0]);
                int high_y = min(top_right[i][1], top_right[j][1]);
                if (high_x > low_x && high_y > low_y) {
                    long long side = min(high_x - low_x, high_y - low_y);
                    max_side = max(max_side, side);
                }
            }
        }
        return max_side * max_side;
    }
};
