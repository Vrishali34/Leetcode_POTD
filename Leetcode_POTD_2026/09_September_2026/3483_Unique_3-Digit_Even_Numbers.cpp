class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> valid_nums;
        int digit_count = digits.size();

        for (int idx_hundred = 0; idx_hundred < digit_count; idx_hundred++) {
            for (int idx_ten = 0; idx_ten < digit_count; idx_ten++) {
                if (idx_ten == idx_hundred) continue;
                for (int idx_unit = 0; idx_unit < digit_count; idx_unit++) {
                    if (idx_unit == idx_hundred || idx_unit == idx_ten) continue;

                    int hundred_digit = digits[idx_hundred];
                    int ten_digit = digits[idx_ten];
                    int unit_digit = digits[idx_unit];

                    if (hundred_digit == 0 || unit_digit % 2 != 0) continue;

                    int formed_num = hundred_digit * 100 + ten_digit * 10 + unit_digit;
                    valid_nums.insert(formed_num);
                }
            }
        }

        return valid_nums.size();
    }
};
