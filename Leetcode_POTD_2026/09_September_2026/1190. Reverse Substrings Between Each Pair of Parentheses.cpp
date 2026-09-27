class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> open_idx_stack;
        string char_buf = s;

        for (int pos = 0; pos < char_buf.size(); pos++) {
            if (char_buf[pos] == '(')
                open_idx_stack.push(pos);
            else if (char_buf[pos] == ')') {
                int start_pos = open_idx_stack.top();
                open_idx_stack.pop();
                reverse(char_buf.begin() + start_pos + 1, char_buf.begin() + pos);
            }
        }

        string final_res;
        for (char cur_ch : char_buf)
            if (cur_ch != '(' && cur_ch != ')')
                final_res += cur_ch;

        return final_res;
    }
};
