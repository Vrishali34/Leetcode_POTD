class Solution {
public:
    string processStr(string letters) {
        string text_out = "";
        for (char symbol : letters) {
            if (symbol == '*') {
                if (!text_out.empty()) text_out.pop_back();
            } else if (symbol == '#') {
                text_out += text_out;
            } else if (symbol == '%') {
                reverse(text_out.begin(), text_out.end());
            } else {
                text_out.push_back(symbol);
            }
        }
        return text_out;
    }
};
