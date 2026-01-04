class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total_sum = 0;
        for (int curr_val : nums) {
            int div_count = 0, local_sum = 0;
            for (int factor = 1; factor * factor <= curr_val; ++factor) {
                if (curr_val % factor == 0) {
                    div_count++;
                    local_sum += factor;
                    if (factor * factor != curr_val) {
                        div_count++;
                        local_sum += curr_val / factor;
                    }
                }
                if (div_count > 4) break;
            }
            if (div_count == 4) total_sum += local_sum;
        }
        return total_sum;
    }
};
