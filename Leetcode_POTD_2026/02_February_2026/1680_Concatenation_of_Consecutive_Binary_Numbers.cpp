class Solution {
public:
    int concatenatedBinary(int n) {
        long run_dec = 0, m = 1e9 + 7;
        for (int num_i = 1; num_i <= n; ++num_i) {
            int width = 0;
            for (int temp = num_i; temp > 0; temp >>= 1) width++;
            run_dec = ((run_dec << width) + num_i) % m;
        }
        return run_dec;
    }
};
