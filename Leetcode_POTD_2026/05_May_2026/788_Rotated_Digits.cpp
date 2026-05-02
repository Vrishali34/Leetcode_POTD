class Solution {
public:
    int rotatedDigits(int n) {
        int valid_tally = 0;
        for (int curr_val = 1; curr_val <= n; ++curr_val) {
            bool has_flip = false, bad_digit = false;
            int temp_num = curr_val;
            while (temp_num > 0) {
                int digit = temp_num % 10;
                if (digit == 3 || digit == 4 || digit == 7) { bad_digit = true; break; }
                if (digit == 2 || digit == 5 || digit == 6 || digit == 9) has_flip = true;
                temp_num /= 10;
            }
            if (!bad_digit && has_flip) ++valid_tally;
        }
        return valid_tally;
    }
};
