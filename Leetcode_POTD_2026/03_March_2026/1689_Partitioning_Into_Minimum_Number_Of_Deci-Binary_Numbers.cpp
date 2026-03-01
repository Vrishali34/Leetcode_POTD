class Solution {
public:
    int minPartitions(string n) {
        char peak_digit = '0';
        for (char curr_chr : n) {
            if (curr_chr > peak_digit) peak_digit = curr_chr;
        }
        return peak_digit - '0';
    }
};
