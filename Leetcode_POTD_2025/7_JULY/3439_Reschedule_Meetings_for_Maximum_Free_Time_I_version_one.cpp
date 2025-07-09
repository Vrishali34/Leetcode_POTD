#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int maxFreeTime(int cosmic_bound, int k_moves, std::vector<int>& start_points, std::vector<int>& end_points) {
        std::vector<int> empty_zones;
        empty_zones.push_back(start_points[0]);
        for (int i = 0; i < start_points.size() - 1; ++i) {
            empty_zones.push_back(start_points[i+1] - end_points[i]);
        }
        empty_zones.push_back(cosmic_bound - end_points.back());

        int peak_void = 0;
        int sum_of_voids = 0;
        int target_gaps = k_moves + 1;

        for (int idx = 0; idx < empty_zones.size(); ++idx) {
            sum_of_voids += empty_zones[idx];
            if (idx >= target_gaps - 1) {
                peak_void = std::max(peak_void, sum_of_voids);
                sum_of_voids -= empty_zones[idx - (target_gaps - 1)];
            }
        }
        return peak_void;
    }
};
