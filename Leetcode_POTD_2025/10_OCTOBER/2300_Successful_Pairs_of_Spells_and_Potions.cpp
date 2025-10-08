#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& crystals, std::vector<int>& elixirs, long long goal) {
        int e_len = elixirs.size();
        std::vector<int> results;
        std::sort(elixirs.begin(), elixirs.end());
        for (int c_val : crystals) {
            long long min_p = (goal + c_val - 1) / c_val;
            auto it = std::lower_bound(elixirs.begin(), elixirs.end(), min_p);
            results.push_back(std::distance(it, elixirs.end()));
        }
        return results;
    }
};
