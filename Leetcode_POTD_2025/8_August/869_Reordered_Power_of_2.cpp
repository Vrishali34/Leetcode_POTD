class Solution {
public:
    bool reorderedPowerOf2(int n) {
        std::unordered_map<int, int> digit_counts;
        std::string s = std::to_string(n);
        for (char c : s) {
            digit_counts[c - '0']++;
        }
        
        for (long long i = 1; i <= 1000000000; i *= 2) {
            std::unordered_map<int, int> power_counts;
            std::string p_str = std::to_string(i);
            for (char c : p_str) {
                power_counts[c - '0']++;
            }
            if (digit_counts == power_counts) {
                return true;
            }
        }
        return false;
    }
};
