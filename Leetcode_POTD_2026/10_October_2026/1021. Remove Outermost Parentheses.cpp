class Solution {
public:
    string removeOuterParentheses(string s) {
        string result_str;
        int depth_lvl = 0;

        for (char paren_ch : s) {
            if (paren_ch == '(') {
                if (depth_lvl > 0) result_str += paren_ch;
                depth_lvl++;
            } else {
                depth_lvl--;
                if (depth_lvl > 0) result_str += paren_ch;
            }
        }

        return result_str;
    }
};
