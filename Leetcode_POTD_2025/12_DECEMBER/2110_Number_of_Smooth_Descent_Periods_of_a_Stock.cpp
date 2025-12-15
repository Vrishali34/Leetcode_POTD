class Solution {
public:
    long long getDescentPeriods(std::vector<int>& prices) {
        long long total_smooth_periods = 0;
        int current_descent_length = 1;
        int max_index = prices.size();
        
        if (max_index == 0) return 0;

        total_smooth_periods = 1;
        
        for (int i = 1; i < max_index; ++i) {
            if (prices[i] == prices[i - 1] - 1) {
                current_descent_length++;
            } else {
                current_descent_length = 1;
            }
            total_smooth_periods += current_descent_length;
        }
        return total_smooth_periods;
    }
};
