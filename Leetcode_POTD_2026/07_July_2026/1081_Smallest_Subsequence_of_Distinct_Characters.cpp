class Solution {
public:
    string smallestSubsequence(string s) {
        int fin_pos[26] = {0};
        bool in_res[26] = {false};
        string res_str = "";
        for (int i = 0; i < s.length(); ++i) {
            fin_pos[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.length(); ++i) {
            int char_idx = s[i] - 'a';
            if (in_res[char_idx]) continue;
            while (!res_str.empty() && res_str.back() > s[i] && fin_pos[res_str.back() - 'a'] > i) {
                in_res[res_str.back() - 'a'] = false;
                res_str.pop_back();
            }
            res_str.push_back(s[i]);
            in_res[char_idx] = true;
        }
        return res_str;
    }
};
