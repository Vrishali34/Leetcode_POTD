class Solution {
public:
    bool isValid(string s) {
        stack<char> open_stack;
        unordered_map<char, char> bracket_pair = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char cur_char : s) {
            if (bracket_pair.count(cur_char)) {
                if (open_stack.empty() || open_stack.top() != bracket_pair[cur_char])
                    return false;
                open_stack.pop();
            } else {
                open_stack.push(cur_char);
            }
        }

        return open_stack.empty();
    }
};
