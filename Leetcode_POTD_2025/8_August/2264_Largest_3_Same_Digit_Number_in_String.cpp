class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> possible_goods = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};
        for (const string& candidate : possible_goods) {
            if (num.find(candidate) != string::npos) {
                return candidate;
            }
        }
        return "";
    }
};
