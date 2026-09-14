class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int left_x1 = rec1[0], bottom_y1 = rec1[1], right_x1 = rec1[2], top_y1 = rec1[3];
        int left_x2 = rec2[0], bottom_y2 = rec2[1], right_x2 = rec2[2], top_y2 = rec2[3];

        bool x_overlap = left_x1 < right_x2 && left_x2 < right_x1;
        bool y_overlap = bottom_y1 < top_y2 && bottom_y2 < top_y1;

        return x_overlap && y_overlap;
    }
};
