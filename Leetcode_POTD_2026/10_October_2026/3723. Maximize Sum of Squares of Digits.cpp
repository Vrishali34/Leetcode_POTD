class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        long long digit_cnt = num, sum_left = sum;
        if (sum_left > 9LL * digit_cnt) return "";

        string answer_digits;
        answer_digits.reserve(digit_cnt);

        for (long long pos = 0; pos < digit_cnt; ++pos) {
            int picked_digit = min(9LL, sum_left);
            answer_digits.push_back('0' + picked_digit);
            sum_left -= picked_digit;
        }

        return answer_digits;
    }
};
