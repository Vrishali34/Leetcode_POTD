class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0, max_open = 0;

        for (char cur_ch : s) {
            if (cur_ch == '(') {
                min_open++;
                max_open++;
            } else if (cur_ch == ')') {
                min_open--;
                max_open--;
            } else {
                min_open--;
                max_open++;
            }

            if (max_open < 0) return false;
            if (min_open < 0) min_open = 0;
        }

        return min_open == 0;
    }
};
