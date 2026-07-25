class Solution {
public:
    int maxProduct(int num_val) {
        int max_one = 0, max_two = 0;
        while (num_val > 0) {
            int cur_dig = num_val % 10;
            if (cur_dig > max_one) {
                max_two = max_one;
                max_one = cur_dig;
            } else if (cur_dig > max_two) {
                max_two = cur_dig;
            }
            num_val /= 10;
        }
        return max_one * max_two;
    }
};
