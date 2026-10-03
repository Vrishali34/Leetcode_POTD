class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        stack<int> idx_stack;
        idx_stack.push(-1);

        for (int pos = 0; pos < s.size(); pos++) {
            if (s[pos] == '(') {
                idx_stack.push(pos);
            } else {
                idx_stack.pop();
                if (idx_stack.empty())
                    idx_stack.push(pos);
                else
                    max_len = max(max_len, pos - idx_stack.top());
            }
        }

        return max_len;
    }
};
