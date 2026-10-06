class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_need = 0, close_need = 0;
        for (char bracket_ch : s) {
            if (bracket_ch == '(') {
                open_need++;
            } else {
                if (open_need > 0) open_need--;
                else close_need++;
            }
        }
        return open_need + close_need;
    }
};
