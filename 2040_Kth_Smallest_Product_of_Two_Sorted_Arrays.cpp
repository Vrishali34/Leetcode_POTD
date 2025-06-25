class Solution {
public:
    long long kthSmallestProduct(std::vector<int>& num_arr1, std::vector<int>& num_arr2, long long target_k) {
        long long min_prod_range = -10000000000LL;
        long long max_prod_range = 10000000000LL;
        long long final_ans = 0;

        while (min_prod_range <= max_prod_range) {
            long long current_mid_val = min_prod_range + (max_prod_range - min_prod_range) / 2;
            long long current_count = 0;

            for (long long x_val : num_arr1) {
                if (x_val == 0) {
                    if (current_mid_val >= 0) {
                        current_count += num_arr2.size();
                    }
                } else if (x_val > 0) {
                    long long req_val = current_mid_val / x_val;
                    if (current_mid_val < 0 && current_mid_val % x_val != 0) {
                        req_val--; 
                    }
                    auto it = std::upper_bound(num_arr2.begin(), num_arr2.end(), req_val);
                    current_count += (it - num_arr2.begin());
                } else {
                    long long req_val = current_mid_val / x_val;
                    if (current_mid_val < 0 && current_mid_val % x_val != 0) {
                        req_val++;
                    }
                    auto it = std::lower_bound(num_arr2.begin(), num_arr2.end(), req_val);
                    current_count += (num_arr2.end() - it);
                }
            }

            if (current_count >= target_k) {
                final_ans = current_mid_val;
                max_prod_range = current_mid_val - 1;
            } else {
                min_prod_range = current_mid_val + 1;
            }
        }
        return final_ans;
    }
};
