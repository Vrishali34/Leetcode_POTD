class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int str_len = s.size();
        array<int,26> char_freq{};
        for (char ch : s) char_freq[ch - 'a']++;

        vector<array<int,26>> state_at_step(str_len + 1);
        state_at_step[0] = char_freq;
        string prefix_built(str_len, '?');
        int match_len = 0;

        for (int pos = 0; pos < str_len; pos++) {
            array<int,26> cur_state = state_at_step[pos];
            int target_idx = target[pos] - 'a';
            if (cur_state[target_idx] > 0) {
                cur_state[target_idx]--;
                prefix_built[pos] = target[pos];
                state_at_step[pos + 1] = cur_state;
                match_len++;
            } else break;
        }

        int start_idx = (match_len < str_len) ? match_len : str_len - 1;
        for (int pos = start_idx; pos >= 0; pos--) {
            array<int,26> cur_state = state_at_step[pos];
            int target_idx = target[pos] - 'a';
            int bump_char = -1;
            for (int c = target_idx + 1; c < 26; c++) {
                if (cur_state[c] > 0) { bump_char = c; break; }
            }
            if (bump_char != -1) {
                cur_state[bump_char]--;
                string result_str = prefix_built.substr(0, pos);
                result_str += char('a' + bump_char);
                for (int c = 0; c < 26; c++)
                    result_str += string(cur_state[c], char('a' + c));
                return result_str;
            }
        }
        return "";
    }
};
