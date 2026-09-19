class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int near_x = max(x1, min(xCenter, x2));
        int near_y = max(y1, min(yCenter, y2));
        long long diff_x = xCenter - near_x;
        long long diff_y = yCenter - near_y;
        return diff_x * diff_x + diff_y * diff_y <= (long long)radius * radius;
    }
};
