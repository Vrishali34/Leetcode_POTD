class Solution {
public:
    int numberOfSubstrings(string s) {
        int total_subs = 0, str_len = s.length();
        int last_pos[3] = {-1, -1, -1};
        for (int idx = 0; idx < str_len; ++idx) {
            last_pos[s[idx] - 'a'] = idx;
            total_subs += min({last_pos[0], last_pos[1], last_pos[2]}) + 1;
        }
        return total_subs;
    }
};
