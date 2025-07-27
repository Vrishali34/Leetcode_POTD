#include <vector>
#include <deque>

class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
        int stellar_points = 0;
        std::deque<int> celestial_list;
        if (!nums.empty()) {
            celestial_list.push_back(nums[0]);
        }
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != celestial_list.back()) {
                celestial_list.push_back(nums[i]);
            }
        }
        for (size_t i = 1; i < celestial_list.size() - 1; ++i) {
            if ((celestial_list[i] > celestial_list[i-1] && celestial_list[i] > celestial_list[i+1]) ||
                (celestial_list[i] < celestial_list[i-1] && celestial_list[i] < celestial_list[i+1])) {
                stellar_points++;
            }
        }
        return stellar_points;
    }
};
