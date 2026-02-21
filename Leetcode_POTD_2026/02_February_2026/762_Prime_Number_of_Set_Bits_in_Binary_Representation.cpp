class Solution {
public:
    int bit_tally(int n) {
        return __builtin_popcount(n);
    }
    int countPrimeSetBits(int left, int right) {
        int prime_bit_sum = 0;
        for (int curr_num = left; curr_num <= right; ++curr_num) {
            int active_bits = bit_tally(curr_num);
            if (active_bits == 2 || active_bits == 3 || active_bits == 5 || active_bits == 7 || 
                active_bits == 11 || active_bits == 13 || active_bits == 17 || active_bits == 19) {
                prime_bit_sum++;
            }
        }
        return prime_bit_sum;
    }
};
