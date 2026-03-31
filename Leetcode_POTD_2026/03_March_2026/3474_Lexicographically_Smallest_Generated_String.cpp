class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int total_len = n + m - 1;
        string word(total_len, '$');

        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    if (word[i + j] == '$') word[i + j] = str2[j];
                    else if (word[i + j] != str2[j]) return "";
                }
            }
        }

        string original_word = word;
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
                int blank_count = 0, match_count = 0, last_blank = -1;
                for (int j = 0; j < m; ++j) {
                    if (original_word[i + j] == '$') {
                        if (word[i + j] == '$') word[i + j] = 'a';
                        last_blank = i + j;
                        blank_count++;
                    }
                    if (word[i + j] == str2[j]) match_count++;
                }
                if (match_count == m) {
                    if (blank_count == 0) return "";
                    word[last_blank] = 'b';
                }
            }
        }
        for (char &c : word) if (c == '$') c = 'a';
        return word;
    }
};
