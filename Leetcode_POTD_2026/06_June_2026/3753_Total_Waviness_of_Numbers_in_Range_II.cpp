#include <string>
#include <cstring>

using namespace std;

class Solution {
    long long waviness_memo[17][2][2][11][11][2];
    string bound_limit_str;

    void calculate_range_waviness(int digit_pos, bool tight_bound, bool peak_started, int left_digit, int mid_digit, long long &total_waviness, long long &valid_nums) {
        if (digit_pos == bound_limit_str.length()) {
            total_waviness = 0;
            valid_nums = 1;
            return;
        }
        if (waviness_memo[digit_pos][tight_bound][peak_started][left_digit][mid_digit][0] != -1) {
            total_waviness = waviness_memo[digit_pos][tight_bound][peak_started][left_digit][mid_digit][0];
            valid_nums = waviness_memo[digit_pos][tight_bound][peak_started][left_digit][mid_digit][1];
            return;
        }
        total_waviness = 0;
        valid_nums = 0;
        int max_digit = tight_bound ? (bound_limit_str[digit_pos] - '0') : 9;
        for (int curr_digit = 0; curr_digit <= max_digit; ++curr_digit) {
            bool next_tight = tight_bound && (curr_digit == max_digit);
            if (!peak_started && curr_digit == 0) {
                long long next_waviness = 0, next_nums = 0;
                calculate_range_waviness(digit_pos + 1, next_tight, false, 10, 10, next_waviness, next_nums);
                total_waviness += next_waviness;
                valid_nums += next_nums;
            } else {
                int waviness_score = 0;
                int next_left = 10, next_mid = curr_digit;
                if (peak_started) {
                    if (left_digit != 10) {
                        bool is_peak = (mid_digit > left_digit && mid_digit > curr_digit);
                        bool is_valley = (mid_digit < left_digit && mid_digit < curr_digit);
                        if (is_peak || is_valley) waviness_score = 1;
                    }
                    next_left = mid_digit;
                }
                long long next_waviness = 0, next_nums = 0;
                calculate_range_waviness(digit_pos + 1, next_tight, true, next_left, next_mid, next_waviness, next_nums);
                total_waviness += next_waviness + waviness_score * next_nums;
                valid_nums += next_nums;
            }
        }
        waviness_memo[digit_pos][tight_bound][peak_started][left_digit][mid_digit][0] = total_waviness;
        waviness_memo[digit_pos][tight_bound][peak_started][left_digit][mid_digit][1] = valid_nums;
    }

    long long solve_waviness(long long max_range_num) {
        if (max_range_num <= 0) return 0;
        bound_limit_str = to_string(max_range_num);
        memset(waviness_memo, -1, sizeof(waviness_memo));
        long long ans_waviness = 0, ans_nums = 0;
        calculate_range_waviness(0, true, false, 10, 10, ans_waviness, ans_nums);
        return ans_waviness;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve_waviness(num2) - solve_waviness(num1 - 1);
    }
};
