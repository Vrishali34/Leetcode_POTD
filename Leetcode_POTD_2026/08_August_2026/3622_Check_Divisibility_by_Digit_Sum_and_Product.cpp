class Solution {
public:
    bool checkDivisibility(int n) {
        int digit_sum = 0, digit_prod = 1, temp_val = n;
        while (temp_val > 0) {
            int curr_digit = temp_val % 10;
            digit_sum += curr_digit;
            digit_prod *= curr_digit;
            temp_val /= 10;
        }
        return n % (digit_sum + digit_prod) == 0;
    }
};
