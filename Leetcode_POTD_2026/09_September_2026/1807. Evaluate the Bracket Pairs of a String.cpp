class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> key_value_map;
        for (auto& pair_kv : knowledge)
            key_value_map[pair_kv[0]] = pair_kv[1];

        string result_str;
        int str_len = s.size(), char_idx = 0;

        while (char_idx < str_len) {
            if (s[char_idx] == '(') {
                int close_idx = s.find(')', char_idx);
                string key_word = s.substr(char_idx + 1, close_idx - char_idx - 1);
                result_str += key_value_map.count(key_word) ? key_value_map[key_word] : "?";
                char_idx = close_idx + 1;
            } else {
                result_str += s[char_idx++];
            }
        }

        return result_str;
    }
};
