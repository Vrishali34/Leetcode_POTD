class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> depth_stack;
        depth_stack.push(0);
        for (char bracket_ch : s) {
            if (bracket_ch == '(') {
                depth_stack.push(0);
            } else {
                int inner_score = depth_stack.top(); depth_stack.pop();
                int curr_score = (inner_score == 0) ? 1 : 2 * inner_score;
                depth_stack.top() += curr_score;
            }
        }
        return depth_stack.top();
    }
};
