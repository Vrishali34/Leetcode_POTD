class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int total_ticks = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            int gap_x = abs(points[i+1][0] - points[i][0]);
            int gap_y = abs(points[i+1][1] - points[i][1]);
            total_ticks += max(gap_x, gap_y);
        }
        return total_ticks;
    }
};
