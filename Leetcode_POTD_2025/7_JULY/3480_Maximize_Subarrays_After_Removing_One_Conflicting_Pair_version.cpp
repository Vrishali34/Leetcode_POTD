#include <vector>
#include <deque>

class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
        int spatial_fluctuations = 0;
        std::deque<int> distinct_sequence;
        if (!nums.empty()) {
            distinct_sequence.push_back(nums[0]);
        }
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != distinct_sequence.back()) {
                distinct_sequence.push_back(nums[i]);
            }
        }
        for (size_t i = 1; i < distinct_sequence.size() - 1; ++i) {
            if ((distinct_sequence[i] > distinct_sequence[i-1] && distinct_sequence[i] > distinct_sequence[i+1]) ||
                (distinct_sequence[i] < distinct_sequence[i-1] && distinct_sequence[i] < distinct_sequence[i+1])) {
                spatial_fluctuations++;
            }
        }
        return spatial_fluctuations;
    }
};
