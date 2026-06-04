class Solution {
public:
    int totalWaviness(int low_bound, int up_bound) {
        int gross_wave = 0;
        for (int curr_val = low_bound; curr_val <= up_bound; ++curr_val) {
            string dig_str = to_string(curr_val);
            if (dig_str.length() < 3) continue;
            for (size_t idx = 1; idx < dig_str.length() - 1; ++idx) {
                if ((dig_str[idx] > dig_str[idx - 1] && dig_str[idx] > dig_str[idx + 1]) ||
                    (dig_str[idx] < dig_str[idx - 1] && dig_str[idx] < dig_str[idx + 1])) {
                    ++gross_wave;
                }
            }
        }
        return gross_wave;
    }
};
