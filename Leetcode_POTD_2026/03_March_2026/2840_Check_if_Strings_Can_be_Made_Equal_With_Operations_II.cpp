class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int char_freq[2][26] = {0};
        for (int idx = 0; idx < s1.size(); ++idx) {
            char_freq[idx % 2][s1[idx] - 'a']++;
            char_freq[idx % 2][s2[idx] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) 
            if (char_freq[0][i] || char_freq[1][i]) return false;
        return true;
    }
};
