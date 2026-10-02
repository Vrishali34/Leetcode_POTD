class Solution {
public:
    vector<string> result_list;

    void buildCombo(string& combo_str, int open_left, int close_left) {
        if (open_left == 0 && close_left == 0) {
            result_list.push_back(combo_str);
            return;
        }
        if (open_left > 0) {
            combo_str.push_back('(');
            buildCombo(combo_str, open_left - 1, close_left);
            combo_str.pop_back();
        }
        if (close_left > open_left) {
            combo_str.push_back(')');
            buildCombo(combo_str, open_left, close_left - 1);
            combo_str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string combo_str;
        buildCombo(combo_str, n, n);
        return result_list;
    }
};
