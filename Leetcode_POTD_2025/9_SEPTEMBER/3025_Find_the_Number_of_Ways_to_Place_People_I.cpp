class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count = 0;
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        for (size_t i = 0; i < points.size(); ++i) {
            int y_limit = -1;
            for (size_t j = i + 1; j < points.size(); ++j) {
                if (points[j][1] <= points[i][1]) {
                    if (points[j][1] > y_limit) {
                        count++;
                        y_limit = points[j][1];
                    }
                }
            }
        }
        
        return count;
    }
};
