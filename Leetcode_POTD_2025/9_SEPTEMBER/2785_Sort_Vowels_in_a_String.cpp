class Solution {
public:
    string sortVowels(string s) {
        string b_t;
        for (char l_c : s) {
            if (string("aeiouAEIOU").find(l_c) != string::npos) {
                b_t += l_c;
            }
        }
        sort(b_t.begin(), b_t.end());
        int h_j = 0;
        for (int i_d = 0; i_d < s.length(); ++i_d) {
            if (string("aeiouAEIOU").find(s[i_d]) != string::npos) {
                s[i_d] = b_t[h_j++];
            }
        }
        return s;
    }
};
