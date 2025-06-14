class Solution {
public:
    // Version 1: Direct string manipulation
    int minMaxDifference(int num) {
        std::string s_num = std::to_string(num);

        // Max Value Calculation
        std::string max_str = s_num;
        char target_max = ' ';
        for (char c : max_str) {
            if (c != '9') {
                target_max = c;
                break;
            }
        }
        if (target_max != ' ') {
            for (char &c : max_str) {
                if (c == target_max) {
                    c = '9';
                }
            }
        }
        int max_val = std::stoi(max_str);

        // Min Value Calculation
        std::string min_str = s_num;
        char target_min = min_str[0];
        for (char &c : min_str) {
            if (c == target_min) {
                c = '0';
            }
        }
        int min_val = std::stoi(min_str);

        return max_val - min_val;
    }
};
