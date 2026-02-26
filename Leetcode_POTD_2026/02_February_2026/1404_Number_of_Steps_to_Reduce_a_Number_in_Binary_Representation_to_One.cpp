class Solution {
public:
    int numSteps(string s) {
        int total_ops = 0, extra_bit = 0;
        for (int i = s.size() - 1; i > 0; --i) {
            if ((s[i] - '0') + extra_bit == 1) {
                total_ops += 2;
                extra_bit = 1;
            } else {
                total_ops += 1;
            }
        }
        return total_ops + extra_bit;
    }
};
