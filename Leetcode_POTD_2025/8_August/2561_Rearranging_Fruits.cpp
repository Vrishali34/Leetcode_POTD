#include <vector>
#include <numeric>
#include <map>
#include <algorithm>

class Solution {
public:
    long long minCost(std::vector<int>& basket1, std::vector<int>& basket2) {
        std::map<int, int> overall_counts;
        long long global_min_val = 1000000001;

        for (int item : basket1) {
            overall_counts[item]++;
            global_min_val = std::min(global_min_val, (long long)item);
        }
        for (int item : basket2) {
            overall_counts[item]++;
            global_min_val = std::min(global_min_val, (long long)item);
        }

        for (auto const& [item, count] : overall_counts) {
            if (count % 2 != 0) {
                return -1;
            }
        }

        std::map<int, int> b1_counts;
        for (int item : basket1) {
            b1_counts[item]++;
        }

        std::vector<int> b1_excess, b2_excess;
        for (auto const& [item, total_count] : overall_counts) {
            int target_count = total_count / 2;
            int b1_has = b1_counts[item];
            
            if (b1_has > target_count) {
                for (int i = 0; i < b1_has - target_count; ++i) {
                    b1_excess.push_back(item);
                }
            } else if (b1_has < target_count) {
                for (int i = 0; i < target_count - b1_has; ++i) {
                    b2_excess.push_back(item);
                }
            }
        }

        std::sort(b1_excess.begin(), b1_excess.end());
        std::sort(b2_excess.begin(), b2_excess.end(), std::greater<int>());
        
        long long total_expense = 0;
        for (size_t i = 0; i < b1_excess.size(); ++i) {
            long long direct_swap_cost = std::min((long long)b1_excess[i], (long long)b2_excess[i]);
            total_expense += std::min(direct_swap_cost, 2 * global_min_val);
        }

        return total_expense;
    }
};
