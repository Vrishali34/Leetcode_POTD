#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int maxFreeTime(int univ_span, int k_ops, std::vector<int>& begin_moments, std::vector<int>& end_moments) {
        std::vector<int> gap_sizes;
        gap_sizes.push_back(begin_moments[0]);
        for (int i = 0; i < begin_moments.size() - 1; ++i) {
            gap_sizes.push_back(begin_moments[i+1] - end_moments[i]);
        }
        gap_sizes.push_back(univ_span - end_moments.back());

        int max_period = 0;
        int current_sum = 0;
        int window_size = k_ops + 1;

        for (int i = 0; i < gap_sizes.size(); ++i) {
            current_sum += gap_sizes[i];
            if (i >= window_size - 1) {
                max_period = std::max(max_period, current_sum);
                current_sum -= gap_sizes[i - (window_size - 1)];
            }
        }
        return max_period;
    }
};
