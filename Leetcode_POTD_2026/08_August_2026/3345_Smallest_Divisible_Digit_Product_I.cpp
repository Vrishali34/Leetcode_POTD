class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int cand_num = n; ; cand_num++) {
            int digit_prod = 1, tmp_num = cand_num;
            while (tmp_num) { digit_prod *= tmp_num % 10; tmp_num /= 10; }
            if (digit_prod % t == 0) return cand_num;
        }
    }
};
