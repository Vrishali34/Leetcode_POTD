#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        std::unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        int max_len = 0;
        for (auto const& [num_val, num_count] : counts) {
            // Check if num_val + 1 exists in the map
            if (counts.count(num_val + 1)) {
                max_len = std::max(max_len, num_count + counts[num_val + 1]);
            }
        }
        return max_len;
    }
};
