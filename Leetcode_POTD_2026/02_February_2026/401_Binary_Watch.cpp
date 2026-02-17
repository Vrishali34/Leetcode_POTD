class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> valid_times;
        for (int bit_mask = 0; bit_mask < 1024; ++bit_mask) {
            if (__builtin_popcount(bit_mask) == turnedOn) {
                int hr_part = bit_mask >> 6;
                int min_part = bit_mask & 0x3F;
                if (hr_part < 12 && min_part < 60) {
                    valid_times.push_back(to_string(hr_part) + (min_part < 10 ? ":0" : ":") + to_string(min_part));
                }
            }
        }
        return valid_times;
    }
};
